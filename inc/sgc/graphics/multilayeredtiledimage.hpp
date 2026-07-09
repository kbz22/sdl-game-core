#pragma once

#include "sgc/graphics/tiledimage.hpp"
#include "sgc/graphics/idrawable.hpp"
#include "sgc/graphics/rendercontext.hpp"

#include <vector>
#include <memory>

namespace sgc::graphics {

    class MultilayeredTiledImage : public IDrawable {

        private:
            std::vector<std::shared_ptr<TiledImage>> m_layers;

        public:
            MultilayeredTiledImage(const std::vector<std::shared_ptr<TiledImage>>& layers);

            void Draw(const RenderContext& context) override;

    };

}