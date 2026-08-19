#pragma once

#include "sgc/graphics/tiledlayer.hpp"
#include "sgc/graphics/rendercontext.hpp"
#include "sgc/graphics/idrawable.hpp"
#include "sgc/graphics/color.hpp"
#include "sgc/tile/tile.hpp"

#include <memory>
#include <vector>

namespace sgc::graphics {

    class TiledImage : public IDrawable {

        private:
            std::shared_ptr<TiledLayer> m_layer;
            uint8_t m_alpha{ 255 };
            sgc::math::fvec2 m_position{ 0.0f, 0.0f };
            sgc::tile::TilePosition2D m_tilePosition{ 0, 0 };

        public:
            TiledImage(std::shared_ptr<TiledLayer> layer);

            uint8_t GetAlpha() const;            

            void SetAlpha(uint8_t alpha);
            void SetPositionPixels(sgc::math::fvec2 position);
            void SetPositionPixels(sgc::graphics::PixelPosition2D position);

            void Draw(const RenderContext& context) override;            

    };

}