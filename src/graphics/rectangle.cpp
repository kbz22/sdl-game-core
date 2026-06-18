#include "sgc/graphics/rectangle.hpp"

sgc::graphics::Rectangle::Rectangle(int x, int y, int width, int height) :
    m_rect{ x, y, width, height }
{}

sgc::graphics::Rectangle::Rectangle(sgc::math::vec2 position, sgc::math::uvec2 size) :
    m_rect{
        static_cast<int>(position.x),
        static_cast<int>(position.y),
        static_cast<int>(size.x),
        static_cast<int>(size.y)
    }    
{}

sgc::math::vec2 sgc::graphics::Rectangle::GetPosition() const
{
    return sgc::math::vec2{ m_rect.x, m_rect.y };
}

sgc::math::uvec2 sgc::graphics::Rectangle::GetSize() const
{
    return sgc::math::uvec2{ static_cast<unsigned int>(m_rect.w), static_cast<unsigned int>(m_rect.h) };
}

int sgc::graphics::Rectangle::GetAlpha() const
{
    return m_alpha;
}

sgc::graphics::color sgc::graphics::Rectangle::GetColor() const
{
    return m_color;
}

void sgc::graphics::Rectangle::SetPosition(sgc::math::vec2 position)
{
    m_rect.x = static_cast<int>(position.x);
    m_rect.y = static_cast<int>(position.y);
}

void sgc::graphics::Rectangle::SetSize(sgc::math::uvec2 size)
{
    m_rect.w = static_cast<int>(size.x);
    m_rect.h = static_cast<int>(size.y);
}

void sgc::graphics::Rectangle::SetAlpha(int alpha)
{
    m_alpha = alpha;
}

void sgc::graphics::Rectangle::SetColor(sgc::graphics::color color)
{
    m_color = color;
}

void sgc::graphics::Rectangle::Draw(const RenderContext& context)
{
    if (!context.renderer) {
        return;
    }

    SDL_FRect dstRect = {
        static_cast<float>(m_rect.x),
        static_cast<float>(m_rect.y),
        static_cast<float>(m_rect.w),
        static_cast<float>(m_rect.h)
    };

    SDL_SetRenderDrawColor(context.renderer, m_color.r, m_color.g, m_color.b, m_alpha);

    SDL_RenderRect(context.renderer, &dstRect);
}

    