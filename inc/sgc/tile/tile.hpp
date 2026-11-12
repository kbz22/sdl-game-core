#pragma once

#include "sgc/coordinates/position.hpp"
#include <cstdint>

namespace sgc::tile 
{
    struct TileType {};
    using TilePosition2D = coordinates::Position2D<TileType>;
    using TileSize2D = coordinates::Size2D<TileType>;
    using TileOffset2D = coordinates::PositionOffset2D<TileType>;
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