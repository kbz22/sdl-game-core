#pragma once

#include <SDL3/SDL.h>
#include "sgc/graphics/idrawable.hpp"
#include "sgc/graphics/rendercontext.hpp"
#include "sgc/math/vector.hpp"
#include "sgc/graphics/color.hpp"
#include "sgc/graphics/image.hpp"
#include "sgc/tile/tile.hpp"

namespace sgc::graphics {

    class LineGrid : public IDrawable {
        private:            
            graphics::color m_color{ 255, 255, 255, 255 };
            PixelPosition2D m_position{ 0, 0 };
            PixelSize2D m_size{ 0, 0 };
            PixelSize2D m_cellSize{ 32, 32 };

        public:
            LineGrid(int x, int y, int width, int height, int cellWidth, int cellHeight);
            LineGrid(PixelPosition2D position, PixelSize2D size, PixelSize2D cellSize);

            PixelPosition2D GetPosition() const;
            PixelSize2D GetSize() const;
            uint8_t GetAlpha() const;
            graphics::color GetColor() const;
            PixelSize2D GetCellSize() const;

            void SetPosition(PixelPosition2D position);
            void SetSize(PixelSize2D size);
            void SetAlpha(uint8_t alpha);
            void SetColor(graphics::color value);
            void SetCellSize(PixelSize2D cellSize);

            void Draw(const RenderContext& context) override;
    };

}