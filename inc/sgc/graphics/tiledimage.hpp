#pragma once

#include "sgc/graphics/tiledlayer.hpp"
#include "sgc/graphics/rendercontext.hpp"
#include "sgc/graphics/idrawable.hpp"
#include "sgc/graphics/color.hpp"

#include <memory>

namespace sgc::graphics {

    class TiledImage : public IDrawable {

        private:
            std::shared_ptr<TiledLayer> m_layer;
            uint8_t m_alpha{ 255 };

        public:
            TiledImage(std::shared_ptr<TiledLayer> layer);

            uint8_t GetAlpha() const;            

            void SetAlpha(uint8_t alpha);

            void Draw(const RenderContext& context) override;            

    };

}