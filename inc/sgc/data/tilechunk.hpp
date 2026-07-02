#pragma once

#include "sgc/math/vector.hpp"
#include "sgc/tile/tile.hpp"
#include <array>

namespace sgc::data {

    using ChunkCoord = math::vec2;

    struct TileChunk {
        static constexpr sgc::math::uval Size = 32;

        std::array<tile::TileId, Size * Size> tiles;
    };

}