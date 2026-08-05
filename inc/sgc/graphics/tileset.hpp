#pragma once

#include <SDL3/SDL.h>
#include <memory>
#include "sgc/graphics/image.hpp"
#include "sgc/math/vector.hpp"
#include "sgc/tile/tile.hpp"

namespace sgc::graphics {

    class Sprite;

    class Tileset {

        private:
            std::shared_ptr<Image> m_image;
            tile::TileSize2D m_gridSize{ 0, 0 };
            graphics::PixelSize2D m_tileSize{ 0, 0 };

        public:
            Tileset(std::shared_ptr<Image> image, graphics::PixelSize2D tileSize);
            
            SDL_FRect GetTileRect(tile::TileId tileId) const;
            SDL_Texture* GetTexture() const;            
            graphics::PixelSize2D GetTileSize() const;                       
            graphics::PixelSize2D GetImageSize() const;
            tile::TileSize2D GetSizeInTiles() const;
            tile::TileId TileIdCount() const;
            
            bool IsDrawableTileId(tile::TileId tileId) const;

            tile::TileId ToTileId(tile::TilesetPosition2D position) const;
            tile::TileId ToTileId(tile::TilePosition2D position) const;
            tile::TileId ToTileId(math::uval x, math::uval y) const;

            friend class Sprite;           

    };
}
