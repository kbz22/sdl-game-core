#pragma once

#include "sgc/math/vector.hpp"
#include "sgc/graphics/pixel.hpp"

#include <SDL3/SDL.h>
#include <memory>
#include <vector>
#include <filesystem>

namespace sgc::graphics 
{
    class Tileset;    

    struct TextureDeleter {
        void operator()(SDL_Texture* p) const noexcept;
    };

    enum class TextureFilterMode {
        Nearest = SDL_SCALEMODE_NEAREST,
        Linear = SDL_SCALEMODE_LINEAR
    };

    using TexturePtr = std::unique_ptr<SDL_Texture, TextureDeleter>;

    class Image 
    {
        private:
            PixelCount m_width = 0;
            PixelCount m_height = 0;
            TexturePtr m_texture = nullptr;

            void SetTexture(TexturePtr texture, TextureFilterMode filterMode = TextureFilterMode::Nearest);

        public: 
            Image() = default;
            PixelSize2D GetSize() const;
            bool LoadTexture(SDL_Renderer* renderer, std::filesystem::path path, TextureFilterMode filterMode = TextureFilterMode::Nearest);
            bool LoadTexture(SDL_Renderer* renderer, std::vector<uint8_t> data, TextureFilterMode filterMode = TextureFilterMode::Nearest);

        friend class Tileset;
    };

}
