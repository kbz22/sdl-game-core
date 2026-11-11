#pragma once

#include "sgc/graphics/image.hpp"
#include "sgc/graphics/idrawable.hpp"
#include "sgc/graphics/rendercontext.hpp"
#include "sgc/graphics/tileset.hpp"
#include "sgc/math/vector.hpp"
#include "sgc/tile/tile.hpp"

#include <memory>

namespace sgc::graphics {

    class Sprite : public IDrawable {
        private:            
            std::shared_ptr<Tileset> m_tileset;
            PixelPosition2D m_position{ 0, 0 };            
            tile::TileId m_tilesetPosition{ 0 };

        public:
            Sprite(std::shared_ptr<Tileset> tileset, tile::TilePosition2D gridPosition);            

            void SetTilesetPosition(tile::TilePosition2D gridPosition);
            void SetTilesetPosition(tile::TileId tileId);
            void SetPositionPx(PixelPosition2D position);

            void Draw(const RenderContext& context) override;            
    };

}