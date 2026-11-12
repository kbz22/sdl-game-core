#pragma once

#include "sgc/coordinates/position.hpp"
#include "sgc/tile/tile.hpp"

namespace sgc::graphics
{
    using tile::TilePosition2D;

    struct PixelType {};
    using PixelSize2D = coordinates::Size2D<PixelType>;
    using PixelPosition2D = coordinates::Position2D<PixelType>;

    using PixelCount = math::ival;

    inline TilePosition2D GetTilePosition(PixelPosition2D &positionPx, PixelSize2D &tileSize);
    inline PixelPosition2D GetPixelPosition(TilePosition2D &positionTile, PixelSize2D &tileSize);
}