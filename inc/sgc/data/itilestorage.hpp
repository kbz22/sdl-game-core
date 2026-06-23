#pragma once

#include "sgc/types.hpp"

#include <array>
#include <optional>
#include <unordered_map>

namespace sgc::data {

    using ChunkCoord = sgc::math::uvec2;
    using GridCoord = sgc::math::uvec2;       

    class ITileStorage {
        public:
            virtual ~ITileStorage() = default;

            virtual std::optional<tile::TileId> GetTileAt(GridCoord position) const = 0;
            virtual void SetTileAt(GridCoord position, tile::TileId tileId) = 0;            
    };
}