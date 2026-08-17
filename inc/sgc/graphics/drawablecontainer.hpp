#pragma once

#include "sgc/graphics/idrawable.hpp"
#include <vector>
#include <memory>

namespace sgc::graphics {

    class DrawableContainer : public IDrawable {

        private:
            std::vector<std::shared_ptr<IDrawable>> m_drawables;

        public:
            DrawableContainer(std::vector<std::shared_ptr<IDrawable>> drawables);

            void Draw(const RenderContext& context) override;

    };

}