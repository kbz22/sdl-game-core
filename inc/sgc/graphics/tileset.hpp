#pragma once

#include <SDL3/SDL.h>
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
            Tileset(Image& image, math::uvec2 tileSize);
            
            SDL_FRect GetTileRect(math::uvec2 gridPosition);
            SDL_Texture* GetTexture() const;            
            math::uvec2 GetTileSize() const;                       
            math::uvec2 GetImageSize() const;

            friend class Sprite;

    };
}