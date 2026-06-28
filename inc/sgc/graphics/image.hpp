#pragma once

#include "sgc/types.hpp"

#include <SDL3/SDL.h>
#include <memory>
#include <vector>
#include <filesystem>

namespace sgc::graphics {

    class Tileset;

    struct TextureDeleter {
        void operator()(SDL_Texture* p) const noexcept;
    };

    using TexturePtr = std::unique_ptr<SDL_Texture, TextureDeleter>;

    class Image {
        public: 
            Image() = default;
            math::uvec2 GetSize() const;
            bool LoadTexture(SDL_Renderer* renderer, std::filesystem::path path);
            bool LoadTexture(SDL_Renderer* renderer, std::vector<uint8_t> data);

        private:                        
            math::u64 m_width = 0;
            math::u64 m_height = 0;            
            TexturePtr m_texture = nullptr;

            friend class Tileset;            
    };

}
