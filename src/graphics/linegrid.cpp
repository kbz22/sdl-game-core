#include "sgc/graphics/linegrid.hpp"

sgc::graphics::LineGrid::LineGrid(int x, int y, int width, int height, int cellWidth, int cellHeight) :
    m_position{
        static_cast<sgc::math::i64>(x),
        static_cast<sgc::math::i64>(y)
    },
    m_size{
        static_cast<sgc::math::u64>(width),
        static_cast<sgc::math::u64>(height)
    },
    m_cellSize{
        static_cast<sgc::math::u64>(cellWidth),
        static_cast<sgc::math::u64>(cellHeight)
    }
{}

sgc::graphics::LineGrid::LineGrid(sgc::math::vec2 position, sgc::math::uvec2 size, sgc::math::uvec2 cellSize) :
    LineGrid(static_cast<int>(position.x), static_cast<int>(position.y), static_cast<int>(size.x), static_cast<int>(size.y), static_cast<int>(cellSize.x), static_cast<int>(cellSize.y))
{}

sgc::math::vec2 sgc::graphics::LineGrid::GetPosition() const
{
    return m_position;
}

sgc::math::uvec2 sgc::graphics::LineGrid::GetSize() const
{
    return m_size;
}

sgc::math::uvec2 sgc::graphics::LineGrid::GetCellSize() const
{
    return m_cellSize;
}

sgc::graphics::color sgc::graphics::LineGrid::GetColor() const
{
    return m_color;
}

int sgc::graphics::LineGrid::GetAlpha() const
{
    return m_alpha;
}

void sgc::graphics::LineGrid::SetPosition(sgc::math::vec2 position)
{
    m_position = position;
}

void sgc::graphics::LineGrid::SetSize(sgc::math::uvec2 size)
{
    m_size = size;
}

void sgc::graphics::LineGrid::SetCellSize(sgc::math::uvec2 cellSize)
{
    m_cellSize = cellSize;
}

void sgc::graphics::LineGrid::SetColor(sgc::graphics::color color)
{
    m_color = color;
}

void sgc::graphics::LineGrid::SetAlpha(int alpha)
{
    m_alpha = alpha;
}

void sgc::graphics::LineGrid::Draw(const RenderContext& context)
{
    // Set the color and alpha for drawing
    SDL_SetRenderDrawColor(context.renderer, m_color.r, m_color.g, m_color.b, m_alpha);

    // Draw vertical lines
    for (sgc::math::u64 x = 0; x <= m_size.x; x += m_cellSize.x) {
        float lineX = static_cast<float>(m_position.x + x);
        SDL_RenderLine(
            context.renderer,
            lineX,
            static_cast<float>(m_position.y),
            lineX,
            static_cast<float>(m_position.y + m_size.y)
        );
    }

    // Draw horizontal lines
    for (sgc::math::u64 y = 0; y <= m_size.y; y += m_cellSize.y) {
        float lineY = static_cast<float>(m_position.y+y);
        SDL_RenderLine(
            context.renderer,
            static_cast<float>(m_position.x),
            lineY,
            static_cast<float>(m_position.x + m_size.x),
            lineY
        );
    }
}