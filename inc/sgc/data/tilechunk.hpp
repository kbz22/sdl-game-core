#pragma once

#include "sgc/math/vector.hpp"
#include "sgc/math/value.hpp"
#include "sgc/tile/tile.hpp"
#include <array>

namespace sgc::data {

    using ChunkCoord = math::vec2;

    struct TileChunk {
        static constexpr sgc::math::ival Size = 32;

        std::array<tile::TileId, Size * Size> tiles;
    };

}