#pragma once

#include "sgc/math/vector.hpp"
#include "sgc/graphics/idrawable.hpp"
#include "sgc/graphics/color.hpp"
#include "sgc/graphics/rendercontext.hpp"

namespace sgc::graphics
{
    class Line : public IDrawable
    {
        private:
            math::fvec2 m_start;
            math::fvec2 m_end;
            graphics::color m_color{ 255, 255, 255, 255 };

        public:
            Line(math::fvec2 start, math::fvec2 end);
            Line(float startX, float startY, float endX, float endY);

            math::fvec2 GetStart() const;
            math::fvec2 GetEnd() const;
            graphics::color GetColor() const;

            void SetStart(math::fvec2 start);
            void SetEnd(math::fvec2 end);
            void SetColor(graphics::color color);

            void Draw(const RenderContext& context) override;
    };

}