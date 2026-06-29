#pragma once

#include <SDL3/SDL.h>
#include <memory>
#include "sgc/graphics/image.hpp"
#include "sgc/types.hpp"

namespace sgc::graphics {

    class Sprite;

    class Tileset {

        private:
            std::shared_ptr<Image> m_image;
            math::uvec2 m_gridSize{ 0, 0 }; //in tiles            
            math::uvec2 m_tileSize{ 0, 0 }; // in pixels            

        public:
            Tileset(std::shared_ptr<Image> image, math::uvec2 tileSize);
            
            SDL_FRect GetTileRect(tile::TileId tileId) const;
            SDL_Texture* GetTexture() const;            
            math::uvec2 GetTileSize() const;                       
            math::uvec2 GetImageSize() const;
            math::uvec2 GetSizeInTiles() const;

            tile::TileId ToTileId(math::uvec2 position) const;
            tile::TileId ToTileId(math::vec2 position) const;
            tile::TileId ToTileId(math::u64 x, math::u64 y) const;

            friend class Sprite;

    };
}
