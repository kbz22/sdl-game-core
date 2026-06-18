#pragma once

#include "sgc/graphics/tiledlayer.hpp"
#include "sgc/graphics/idrawable.hpp"

namespace sgc::graphics {

    class TiledImage : public IDrawable {

        private:
            std::shared_ptr<TiledLayer> m_layer;
            SDL_Renderer *m_renderer;

        public:
            TiledImage(std::shared_ptr<TiledLayer> layer);

            void Draw() override;
            void SetRenderer(SDL_Renderer *renderer) override;

    };

}