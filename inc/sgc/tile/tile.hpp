#pragma once

#include <cstdint>
#include "sgc/math/vector.hpp"

namespace sgc::tile 
{
    struct TilePosition2D : public math::vec2 {};
    struct TileSize2D : public math::vec2 {};
    using TileId = uint32_t;

    struct Tile {        
        TilePosition2D position;
        TileId id;
    };
    
}

namespace std
{
    template<>
    struct hash<sgc::tile::TilePosition2D> 
    {
        size_t operator()(const sgc::tile::TilePosition2D& v) const noexcept {
            return hash<sgc::math::vec2>{}(v);
        }
    };
}