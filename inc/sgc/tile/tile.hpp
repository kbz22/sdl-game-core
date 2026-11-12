#pragma once

#include <cstdint>
#include "sgc/math/vector.hpp"

namespace sgc::tile 
{
    struct TilePosition2D : public math::vec2 
    {
        TilePosition2D() = default;
        TilePosition2D(const TilePosition2D&) = default;
        TilePosition2D(const math::ival &x, const math::ival &y) : math::vec2{x,y} {}
        TilePosition2D(const math::vec2& other) : math::vec2{other} {}
        TilePosition2D& operator=(const math::vec2& other)
        {
            x = other.x;
            y = other.y;

            return *this;
        }
    };

    struct TileSize2D : public math::vec2 
    {
        TileSize2D() = default;
        TileSize2D(const TileSize2D&) = default;
        TileSize2D(const math::ival &x, const math::ival &y) : math::vec2{x,y} {}
        TileSize2D(const math::vec2& other) : math::vec2{other} {}
        TileSize2D& operator=(const math::vec2& other)
        {
            x = other.x;
            y = other.y;

            return *this;
        }
    };
    
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