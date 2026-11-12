#pragma once

#include "sgc/math/vector.hpp"

namespace sgc::coordinates
{
    template<class Type>
    struct PositionOffset2D;

    template<class Type>
    struct Position2D : public math::vec2
    {
        Position2D() = default;
        Position2D(const Position2D&) = default;
        Position2D(const math::ival &x, const math::ival &y) : math::vec2{x,y} {}
        Position2D(const math::vec2& other) : math::vec2{other} {}
        
        Position2D& operator=(const math::vec2& other)
        {
            x = other.x;
            y = other.y;

            return *this;
        }

        Position2D& operator+(const math::vec2& other)
        {
            x = x + other.x;
            y = y + other.y;

            return *this;
        }

        Position2D& operator+(const PositionOffset2D<Type>& other)
        {
            x = x + other.x;
            y = y + other.y;

            return *this;
        }

        Position2D& operator-(const PositionOffset2D<Type>& other)
        {
            x = x - other.x;
            y = y - other.y;

            return *this;
        }

        PositionOffset2D<Type> operator-(const Position2D& other)
        {
            return sgc::coordinates::PositionOffset2D<Type>{
                x - other.x,
                y - other.y
            };
        }
    };

    template<class Type>
    struct Size2D : public math::vec2
    {
        Size2D() = default;
        Size2D(const Size2D&) = default;
        Size2D(const math::ival &x, const math::ival &y) : math::vec2{x,y} {}        
        Size2D(const math::vec2& other) : math::vec2{other} {}
        Size2D& operator=(const math::vec2& other)
        {
            x = other.x;
            y = other.y;

            return *this;
        }
    };

    template<class Type>
    struct PositionOffset2D : public math::vec2
    {
        PositionOffset2D() = default;
        PositionOffset2D(const PositionOffset2D&) = default;
        PositionOffset2D(const math::ival &x, const math::ival &y) : math::vec2{x,y} {}
        PositionOffset2D(const math::vec2& other) : math::vec2{other} {}
        PositionOffset2D& operator=(const math::vec2& other)
        {
            x = other.x;
            y = other.y;

            return *this;
        }
    };

    template<class Type>
    struct SinglesPositionOffset2D;

    template<class Type>
    struct SinglesPosition2D : public math::fvec2
    {
        SinglesPosition2D() = default;
        SinglesPosition2D(const SinglesPosition2D&) = default;
        SinglesPosition2D(const float &x, const float &y) : math::fvec2{x,y} {}
        SinglesPosition2D(const math::fvec2& other) : math::fvec2{other} {}
        
        SinglesPosition2D& operator=(const math::fvec2& other)
        {
            x = other.x;
            y = other.y;

            return *this;
        }

        SinglesPosition2D& operator+(const math::fvec2& other)
        {
            x = x + other.x;
            y = y + other.y;

            return *this;
        }

        SinglesPosition2D& operator+(const SinglesPositionOffset2D<Type>& other)
        {
            x = x + other.x;
            y = y + other.y;

            return *this;
        }

        SinglesPosition2D& operator-(const SinglesPositionOffset2D<Type>& other)
        {
            x = x - other.x;
            y = y - other.y;

            return *this;
        }

        SinglesPositionOffset2D<Type> operator-(const SinglesPosition2D& other)
        {
            return sgc::coordinates::SinglesPositionOffset2D<Type>{
                x - other.x,
                y - other.y
            };
        }
    };

    template<class Type>
    struct SinglesPositionOffset2D : public math::fvec2
    {
        SinglesPositionOffset2D() = default;
        SinglesPositionOffset2D(const SinglesPositionOffset2D&) = default;
        SinglesPositionOffset2D(const float &x, const float &y) : math::fvec2{x,y} {}
        SinglesPositionOffset2D(const math::fvec2& other) : math::fvec2{other} {}
        SinglesPositionOffset2D& operator=(const math::fvec2& other)
        {
            x = other.x;
            y = other.y;

            return *this;
        }
    };
}