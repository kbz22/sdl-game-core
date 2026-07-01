#pragma once

#include "sgc/math/vector.hpp"
#include "sgc/data/tileid.hpp"

#include <array>
#include <optional>
#include <unordered_map>

namespace sgc::data {

    using ChunkCoord = sgc::math::uvec2;
    using GridCoord = sgc::math::uvec2;       

    class ITileStorage {
        public:
            virtual ~ITileStorage() = default;

            virtual std::optional<data::TileId> GetTileAt(GridCoord position) const = 0;
            virtual void SetTileAt(GridCoord position, data::TileId tileId) = 0;            
    };
}