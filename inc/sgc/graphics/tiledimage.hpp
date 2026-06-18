#pragma once

#include "sgc/graphics/tiledlayer.hpp"
#include "sgc/graphics/idrawable.hpp"

namespace sgc::graphics {

    class TiledImage : public IDrawable {

        private:
            std::shared_ptr<TiledLayer> m_layer;            

        public:
            TiledImage(std::shared_ptr<TiledLayer> layer);

            void Draw(const RenderContext& context) override;            

    };

}