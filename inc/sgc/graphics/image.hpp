#pragma once

#include "sgc/math/vector.hpp"

#include <SDL3/SDL.h>
#include <memory>
#include <vector>
#include <filesystem>

namespace sgc::graphics {

    using PixelSize2D = math::vec2;
    using PixelPosition2D = math::vec2;
    using PixelCount = math::ival;

    class Tileset;    

    struct TextureDeleter {
        void operator()(SDL_Texture* p) const noexcept;
    };

    using TexturePtr = std::unique_ptr<SDL_Texture, TextureDeleter>;

    class Image {
        public: 
            Image() = default;
            PixelSize2D GetSize() const;
            bool LoadTexture(SDL_Renderer* renderer, std::filesystem::path path);
            bool LoadTexture(SDL_Renderer* renderer, std::vector<uint8_t> data);

        private:                        
            PixelCount m_width = 0;
            PixelCount m_height = 0;            
            TexturePtr m_texture = nullptr;

            friend class Tileset;            
    };

}
