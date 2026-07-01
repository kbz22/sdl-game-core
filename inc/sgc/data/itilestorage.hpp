#pragma once

#include "sgc/math/vector.hpp"
#include "sgc/tile/tile.hpp"

#include <array>
#include <optional>
#include <unordered_map>

namespace sgc::data {

    using ChunkCoord = math::vec2;
    using GridCoord = tile::TilePosition2D;

    class ITileStorage {
        public:
            virtual ~ITileStorage() = default;

            virtual std::optional<tile::TileId> GetTileAt(GridCoord position) const = 0;
            virtual void SetTileAt(GridCoord position, tile::TileId tileId) = 0;            
    };
}