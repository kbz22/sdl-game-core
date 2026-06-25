#pragma once

#include <SDL3/SDL.h>
#include "sgc/graphics/idrawable.hpp"
#include "sgc/graphics/rendercontext.hpp"
#include "sgc/types.hpp"

namespace sgc::graphics {

    class LineGrid : public IDrawable {
        private:            
            int m_alpha = 255;
            graphics::color m_color{ 255, 255, 255, 255 };
            math::vec2 m_position{ 0, 0 };
            math::uvec2 m_size{ 0, 0 };
            math::uvec2 m_cellSize{ 32, 32 };

        public:
            LineGrid(int x, int y, int width, int height, int cellWidth, int cellHeight);
            LineGrid(math::vec2 position, math::uvec2 size, math::uvec2 cellSize);

            math::vec2 GetPosition() const;
            math::uvec2 GetSize() const;
            int GetAlpha() const;
            graphics::color GetColor() const;
            math::uvec2 GetCellSize() const;

            void SetPosition(math::vec2 position);
            void SetSize(math::uvec2 size);
            void SetAlpha(int alpha);
            void SetColor(graphics::color value);
            void SetCellSize(math::uvec2 cellSize);

            void Draw(const RenderContext& context) override;
    };

}