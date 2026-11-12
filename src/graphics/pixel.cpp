#include "sgc/graphics/pixel.hpp"

using   sgc::tile::TilePosition2D,
        sgc::graphics::PixelPosition2D,
        sgc::graphics::PixelSize2D;

inline TilePosition2D GetTilePosition(PixelPosition2D &positionPx, PixelSize2D &tileSize)
{
    return TilePosition2D{
        positionPx.x / tileSize.x,
        positionPx.y / tileSize.y,
    };
}

inline PixelPosition2D GetPixelPosition(TilePosition2D &positionTile, PixelSize2D &tileSize)
{
    return PixelPosition2D{
        positionTile.x * tileSize.x,
        positionTile.y * tileSize.y,
    };
}