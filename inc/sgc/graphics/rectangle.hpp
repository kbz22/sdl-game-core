#pragma once

#include "sgc/graphics/image.hpp"
#include "sgc/graphics/idrawable.hpp"
#include "sgc/types.hpp"
#include <memory>

namespace sgc::graphics {

    class Rectangle : public IDrawable {
        private:            
            SDL_Renderer *m_renderer = nullptr;
            SDL_Rect m_rect;
            int m_alpha = 255;
            graphics::color m_color{ 255, 255, 255, 255 };

        public:
            Rectangle(int x, int y, int width, int height);
            Rectangle(math::vec2 position, math::uvec2 size);

            math::vec2 GetPosition() const;
            math::uvec2 GetSize() const;
            int GetAlpha() const;
            graphics::color GetColor() const;

            void SetPosition(math::vec2 position);
            void SetSize(math::uvec2 size);
            void SetAlpha(int alpha);
            void SetColor(graphics::color color);
        
            void SetRenderer(SDL_Renderer *renderer);
            void Draw();
    };

}

