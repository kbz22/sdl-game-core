#include "sgc/graphics/image.hpp"
#include "sgc/debug/log.hpp"
#include <SDL3_image/SDL_image.h>

bool sgc::graphics::Image::LoadTexture(SDL_Renderer* renderer, std::filesystem::path path)
{    
    using namespace sgc;
    sgc::graphics::TexturePtr texture(IMG_LoadTexture(renderer, path.string().c_str()));

    if (!texture) {
        debug::log(debug::LogMessage("Failed to load image: " + std::string(SDL_GetError())));
        return false;
    }

    float width = 0.0f;
    float height = 0.0f;
    if (!SDL_GetTextureSize(texture.get(), &width, &height)) {
        debug::log(debug::LogMessage("Failed to get texture size: " + std::string(SDL_GetError())));
        return false;
    }

    m_width = static_cast<math::u64>(width);
    m_height = static_cast<math::u64>(height);

    m_texture = std::move(texture);
    
    return true;
}

sgc::math::uvec2 sgc::graphics::Image::GetSize() const
{
    return { m_width, m_height };
}

void sgc::graphics::TextureDeleter::operator()(SDL_Texture* p) const noexcept
{
    if (p) {
        SDL_DestroyTexture(p);
    }
}