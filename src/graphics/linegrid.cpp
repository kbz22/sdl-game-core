#include "sgc/graphics/linegrid.hpp"
#include "sgc/coordinates/screenworld.hpp"

sgc::graphics::LineGrid::LineGrid(int x, int y, int width, int height, int cellWidth, int cellHeight) :
    m_position{
        static_cast<sgc::math::ival>(x),
        static_cast<sgc::math::ival>(y)
    },
    m_size{
        static_cast<sgc::math::uval>(width),
        static_cast<sgc::math::uval>(height)
    },
    m_cellSize{
        static_cast<sgc::math::uval>(cellWidth),
        static_cast<sgc::math::uval>(cellHeight)
    }
{}

sgc::graphics::LineGrid::LineGrid(sgc::graphics::PixelPosition2D position, sgc::graphics::PixelSize2D size, sgc::graphics::PixelSize2D cellSize) :
    LineGrid(static_cast<int>(position.x), static_cast<int>(position.y), static_cast<int>(size.x), static_cast<int>(size.y), static_cast<int>(cellSize.x), static_cast<int>(cellSize.y))
{}

sgc::graphics::PixelPosition2D sgc::graphics::LineGrid::GetPosition() const
{
    return m_position;
}

sgc::graphics::PixelSize2D sgc::graphics::LineGrid::GetSize() const
{
    return m_size;
}

sgc::graphics::PixelSize2D sgc::graphics::LineGrid::GetCellSize() const
{
    return m_cellSize;
}

sgc::graphics::color sgc::graphics::LineGrid::GetColor() const
{
    return m_color;
}

uint8_t sgc::graphics::LineGrid::GetAlpha() const
{
    return m_color.a;
}

void sgc::graphics::LineGrid::SetPosition(sgc::graphics::PixelPosition2D position)
{
    m_position = position;
}

void sgc::graphics::LineGrid::SetSize(sgc::graphics::PixelSize2D size)
{
    m_size = size;
}

void sgc::graphics::LineGrid::SetCellSize(sgc::graphics::PixelSize2D cellSize)
{
    m_cellSize = cellSize;
}

void sgc::graphics::LineGrid::SetColor(sgc::graphics::color color)
{
    m_color = color;
}

void sgc::graphics::LineGrid::SetAlpha(uint8_t alpha)
{
    m_color.a = alpha;
}

void sgc::graphics::LineGrid::Draw(const RenderContext& context)
{
    if (!context.renderer) {
        return;
    }

    SDL_SetRenderDrawColor(
        context.renderer,
        m_color.r,
        m_color.g,
        m_color.b,
        m_color.a
    );
    
    for (sgc::math::ival x = 0; x <= m_size.x; x += m_cellSize.x)
    {
        auto worldStart = sgc::math::fvec2{
            static_cast<float>(m_position.x + x),
            static_cast<float>(m_position.y)
        };

        auto worldEnd = sgc::math::fvec2{
            static_cast<float>(m_position.x + x),
            static_cast<float>(m_position.y + m_size.y)
        };

        auto screenStart = sgc::coordinates::WorldToScreen(
            worldStart,
            context.view
        );

        auto screenEnd = sgc::coordinates::WorldToScreen(
            worldEnd,
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
    
    for (sgc::math::ival y = 0; y <= m_size.y; y += m_cellSize.y)
    {
        auto worldStart = sgc::math::fvec2{
            static_cast<float>(m_position.x),
            static_cast<float>(m_position.y + y)
        };

        auto worldEnd = sgc::math::fvec2{
            static_cast<float>(m_position.x + m_size.x),
            static_cast<float>(m_position.y + y)
        };

        auto screenStart = sgc::coordinates::WorldToScreen(
            worldStart,
            context.view
        );

        auto screenEnd = sgc::coordinates::WorldToScreen(
            worldEnd,
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
}