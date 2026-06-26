#include "sgc/graphics/rectangle.hpp"

sgc::graphics::Rectangle::Rectangle(int x, int y, int width, int height) :
    m_rect{
        static_cast<float>(x),
        static_cast<float>(y),
        static_cast<float>(width),
        static_cast<float>(height)
    }
{}

sgc::graphics::Rectangle::Rectangle(sgc::math::vec2 position, sgc::math::uvec2 size) :
    m_rect{
        static_cast<float>(position.x),
        static_cast<float>(position.y),
        static_cast<float>(size.x),
        static_cast<float>(size.y)
    }    
{}

sgc::math::vec2 sgc::graphics::Rectangle::GetPosition() const
{
    return sgc::math::vec2{
        static_cast<sgc::math::i64>(m_rect.x),
        static_cast<sgc::math::i64>(m_rect.y)
    };
}

sgc::math::uvec2 sgc::graphics::Rectangle::GetSize() const
{
    return sgc::math::uvec2{
        static_cast<sgc::math::u64>(m_rect.w),
        static_cast<sgc::math::u64>(m_rect.h)
    };
}

int sgc::graphics::Rectangle::GetAlpha() const
{
    return m_color.a;
}

sgc::graphics::color sgc::graphics::Rectangle::GetColor() const
{
    return m_color;
}

void sgc::graphics::Rectangle::SetPosition(sgc::math::vec2 position)
{
    m_rect.x = static_cast<float>(position.x);
    m_rect.y = static_cast<float>(position.y);
}

void sgc::graphics::Rectangle::SetSize(sgc::math::uvec2 size)
{
    m_rect.w = static_cast<float>(size.x);
    m_rect.h = static_cast<float>(size.y);
}

void sgc::graphics::Rectangle::SetAlpha(int alpha)
{
    m_color.a = alpha;
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

    SDL_SetRenderDrawColor(context.renderer, m_color.r, m_color.g, m_color.b, m_color.a);

    SDL_RenderRect(context.renderer, &m_rect);
}

    