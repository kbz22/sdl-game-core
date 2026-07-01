#pragma once

#include "sgc/graphics/image.hpp"
#include "sgc/graphics/idrawable.hpp"
#include "sgc/graphics/rendercontext.hpp"
#include "sgc/math/vector.hpp"
#include "sgc/graphics/color.hpp"
#include <memory>

namespace sgc::graphics {

    class Rectangle : public IDrawable {
        private:            
            SDL_FRect m_rect;            
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
            
            void Draw(const RenderContext& context) override;
    };

}

