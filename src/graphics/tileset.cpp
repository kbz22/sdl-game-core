#include "sgc/graphics/tileset.hpp"

sgc::graphics::Tileset::Tileset(sgc::graphics::Image &image, sgc::math::uvec2 tileSize) :
    m_image(std::make_shared<Image>(std::move(image))),
    m_tileSize(tileSize)
{    
    m_gridSize.x = m_image->m_width / m_tileSize.x;
    m_gridSize.y = m_image->m_height / m_tileSize.y;
}

SDL_FRect sgc::graphics::Tileset::GetTileRect(tile::TileId id) const
{
    const sgc::math::uvec2 tilePosition{
        id % m_gridSize.x,
        id / m_gridSize.x
    };

    SDL_FRect rect;

    rect.x = static_cast<float>(tilePosition.x * m_tileSize.x);
    rect.y = static_cast<float>(tilePosition.y * m_tileSize.y);
    rect.w = static_cast<float>(m_tileSize.x);
    rect.h = static_cast<float>(m_tileSize.y);

    return rect;
}

SDL_Texture* sgc::graphics::Tileset::GetTexture() const
{
    return m_image->m_texture.get();
}

sgc::math::uvec2 sgc::graphics::Tileset::GetTileSize() const
{
    return m_tileSize;
}

sgc::math::uvec2 sgc::graphics::Tileset::GetImageSize() const
{
    return m_image->GetSize();
}

sgc::math::uvec2 sgc::graphics::Tileset::GetSizeInTiles() const
{
    return m_gridSize;
}