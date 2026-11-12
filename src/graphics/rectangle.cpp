#include "sgc/graphics/rectangle.hpp"
#include "sgc/coordinates/screenworld.hpp"

sgc::graphics::Rectangle::Rectangle(int x, int y, int width, int height) :
    m_rect{
        static_cast<float>(x),
        static_cast<float>(y),
        static_cast<float>(width),
        static_cast<float>(height)
    }
{}

sgc::graphics::Rectangle::Rectangle(sgc::graphics::PixelPosition2D position, sgc::graphics::PixelSize2D size) :
    m_rect{
        static_cast<float>(position.x),
        static_cast<float>(position.y),
        static_cast<float>(size.x),
        static_cast<float>(size.y)
    }    
{}

sgc::graphics::PixelPosition2D sgc::graphics::Rectangle::GetPosition() const
{
    return sgc::graphics::PixelPosition2D{
        static_cast<sgc::math::ival>(m_rect.x),
        static_cast<sgc::math::ival>(m_rect.y)
    };
}

sgc::graphics::PixelSize2D sgc::graphics::Rectangle::GetSize() const
{
    return sgc::graphics::PixelSize2D{
        static_cast<sgc::math::ival>(m_rect.w),
        static_cast<sgc::math::ival>(m_rect.h)
    };
}

uint8_t sgc::graphics::Rectangle::GetAlpha() const
{
    return m_color.a;
}

sgc::graphics::color sgc::graphics::Rectangle::GetColor() const
{
    return m_color;
}

void sgc::graphics::Rectangle::SetPosition(sgc::graphics::PixelPosition2D position)
{
    m_rect.x = static_cast<float>(position.x);
    m_rect.y = static_cast<float>(position.y);
}

void sgc::graphics::Rectangle::SetSize(sgc::graphics::PixelSize2D size)
{
    m_rect.w = static_cast<float>(size.x);
    m_rect.h = static_cast<float>(size.y);
}

void sgc::graphics::Rectangle::SetAlpha(uint8_t alpha)
{
    m_color.a = alpha;
}

void sgc::graphics::Rectangle::SetColor(sgc::graphics::color color)
{
    m_color = color;
}

void sgc::graphics::Rectangle::Draw(const RenderContext& context)
{
    if (!context.renderer)
        return;

    SDL_SetRenderDrawColor(
        context.renderer,
        m_color.r,
        m_color.g,
        m_color.b,
        m_color.a
    );

    auto position = coordinates::WorldToScreen(
        {m_rect.x, m_rect.y},
        context.view
    );

    auto size = coordinates::WorldToScreen(
        {m_rect.x + m_rect.w, m_rect.y + m_rect.h},
        context.view
    );

    SDL_FRect screenRect{
        position.x,
        position.y,
        size.x - position.x,
        size.y - position.y
    };

    SDL_RenderRect(context.renderer, &screenRect);
}

    