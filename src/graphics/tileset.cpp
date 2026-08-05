#include "sgc/graphics/tileset.hpp"
#include <memory>

sgc::graphics::Tileset::Tileset(std::shared_ptr<Image> image, graphics::PixelSize2D tileSize) :
    m_image(image),
    m_tileSize(tileSize)
{    
    m_gridSize.x = m_image->m_width / m_tileSize.x;
    m_gridSize.y = m_image->m_height / m_tileSize.y;
}

SDL_FRect sgc::graphics::Tileset::GetTileRect(tile::TileId id) const
{
    const tile::TilesetPosition2D tilePosition{
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

sgc::graphics::PixelSize2D sgc::graphics::Tileset::GetTileSize() const
{
    return m_tileSize;
}

sgc::graphics::PixelSize2D sgc::graphics::Tileset::GetImageSize() const
{
    return m_image->GetSize();
}

sgc::tile::TileSize2D sgc::graphics::Tileset::GetSizeInTiles() const
{
    return m_gridSize;
}

sgc::tile::TileId sgc::graphics::Tileset::TileIdCount() const
{
    return static_cast<tile::TileId>(m_gridSize.x * m_gridSize.y);
}

bool sgc::graphics::Tileset::IsDrawableTileId(tile::TileId tileId) const
{
    return tileId < (m_gridSize.x * m_gridSize.y);
}

sgc::tile::TileId sgc::graphics::Tileset::ToTileId(math::uval x, math::uval y) const
{
    return static_cast<tile::TileId>(y * m_gridSize.x + x);
}

sgc::tile::TileId sgc::graphics::Tileset::ToTileId(tile::TilesetPosition2D position) const
{
    return ToTileId(static_cast<math::uval>(position.x), static_cast<math::uval>(position.y));
}

sgc::tile::TileId sgc::graphics::Tileset::ToTileId(tile::TilePosition2D position) const
{
    return ToTileId(position.x, position.y);
}
