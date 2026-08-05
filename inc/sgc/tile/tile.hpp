#pragma once

#include <cstdint>
#include "sgc/math/vector.hpp"

namespace sgc::tile {
    
    using TileId = uint32_t;
    using TilePosition2D = sgc::math::vec2;
    using TilesetPosition2D = sgc::math::uvec2;
    using TileSize2D = sgc::math::vec2;

    struct Tile {        
        TilePosition2D position;
        TileId id;
    };
    
}
