#pragma once

#include "sgc/math/vector.hpp"
#include "sgc/tile/tile.hpp"

#include <vector>
#include <optional>
#include <unordered_map>

namespace sgc::data {
        
    using GridCoord = tile::TilePosition2D;
    using GridSize = tile::TileSize2D;

    class ITileStorage {
        public:
            virtual ~ITileStorage() = default;

            virtual std::optional<tile::TileId> GetTileAt(GridCoord position) const = 0;
            virtual void GetTilesWithin(GridCoord boundStart, GridCoord boundEnd, std::vector<tile::Tile>& tileBuffer) const = 0;

            virtual void SetTileAt(GridCoord position, std::optional<tile::TileId> tileId) = 0;
    };
}