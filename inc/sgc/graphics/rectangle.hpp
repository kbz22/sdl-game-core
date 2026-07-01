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
            Rectangle(PixelPosition2D position, PixelSize2D size);            

            PixelPosition2D GetPosition() const;
            PixelSize2D GetSize() const;
            int GetAlpha() const;
            graphics::color GetColor() const;

            void SetPosition(PixelPosition2D position);
            void SetSize(PixelSize2D size);
            void SetAlpha(int alpha);
            void SetColor(graphics::color color);        
            
            void Draw(const RenderContext& context) override;
    };

}

