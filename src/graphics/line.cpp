#include "sgc/graphics/line.hpp"
#include "sgc/coordinates/screenworld.hpp"

sgc::graphics::Line::Line(math::fvec2 start, math::fvec2 end) :
    m_start{ start },
    m_end{ end }
{}

sgc::graphics::Line::Line(float startX, float startY, float endX, float endY) :
    Line(
        sgc::math::fvec2{ startX, startY },
        sgc::math::fvec2{ endX, endY }
    )
{}

sgc::math::fvec2 sgc::graphics::Line::GetStart() const
{
    return m_start;
}

sgc::math::fvec2 sgc::graphics::Line::GetEnd() const
{
    return m_end;
}

sgc::graphics::color sgc::graphics::Line::GetColor() const
{
    return m_color;
}

void sgc::graphics::Line::SetStart(sgc::math::fvec2 start)
{
    m_start = start;
}

void sgc::graphics::Line::SetEnd(sgc::math::fvec2 end)
{
    m_end = end;
}

void sgc::graphics::Line::SetColor(sgc::graphics::color color)
{
    m_color = color;
}

void sgc::graphics::Line::Draw(const RenderContext& context)
{
    if (!context.renderer)
    {
        return;
    }

    SDL_SetRenderDrawColor(
        context.renderer,
        m_color.r,
        m_color.g,
        m_color.b,
        m_color.a
    );

    auto screenStart = coordinates::WorldToScreen(
        m_start,
        context.view
    );

    auto screenEnd = coordinates::WorldToScreen(
        m_end,
        context.view
    );

    SDL_RenderLine(
        context.renderer,
        screenStart.x,
        screenStart.y,
        screenEnd.x,
        screenEnd.y
    );
}