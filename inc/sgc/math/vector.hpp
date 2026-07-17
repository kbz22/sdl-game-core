#pragma once

#include <functional>
#include "sgc/math/value.hpp"

namespace sgc::math {    

    struct vec2 {
        ival x;
        ival y;

        bool operator==(const vec2& other) const noexcept
        {
            return x == other.x && y == other.y;
        }
    };

    struct uvec2 {
        uval x;
        uval y;

        bool operator==(const uvec2& other) const noexcept
        {
            return x == other.x && y == other.y;
        }
    };

    struct fvec2 {
        float x;
        float y;

        bool operator==(const fvec2& other) const noexcept
        {
            return x == other.x && y == other.y;
        }
    };

    struct vec4 {
        ival x;
        ival y;
        ival z;
        ival w;

        bool operator==(const vec4& other) const noexcept
        {
            return x == other.x && y == other.y && z == other.z && w == other.w;
        }
    };

    struct uvec4 {
        uval x;
        uval y;
        uval z;
        uval w;

        bool operator==(const uvec4& other) const noexcept
        {
            return x == other.x && y == other.y && z == other.z && w == other.w;
        }
    };

    struct fvec4 {
        float x;
        float y;
        float z;
        float w;

        bool operator==(const fvec4& other) const noexcept
        {
            return x == other.x && y == other.y && z == other.z && w == other.w;
        }
    };

}

namespace std
{
    template<>
    struct hash<sgc::math::uvec2>
    {
        size_t operator()(const sgc::math::uvec2& v) const noexcept
        {
            return std::hash<sgc::math::uval>{}(v.x)
                 ^ (std::hash<sgc::math::uval>{}(v.y) << 1);
        }
    };

    template<>
    struct hash<sgc::math::vec2>
    {
        size_t operator()(const sgc::math::vec2& v) const noexcept
        {
            return std::hash<sgc::math::ival>{}(v.x)
                 ^ (std::hash<sgc::math::ival>{}(v.y) << 1);
        }
    };

    template<>
    struct hash<sgc::math::fvec2>
    {
        size_t operator()(const sgc::math::fvec2& v) const noexcept
        {
            return std::hash<float>{}(v.x)
                 ^ (std::hash<float>{}(v.y) << 1);
        }
    };

    template<>
    struct hash<sgc::math::vec4>
    {
        size_t operator()(const sgc::math::vec4& v) const noexcept
        {
            return std::hash<sgc::math::ival>{}(v.x)
                 ^ (std::hash<sgc::math::ival>{}(v.y) << 1)
                 ^ (std::hash<sgc::math::ival>{}(v.z) << 2)
                 ^ (std::hash<sgc::math::ival>{}(v.w) << 3);
        }
    };

    template<>
    struct hash<sgc::math::uvec4>
    {
        size_t operator()(const sgc::math::uvec4& v) const noexcept
        {
            return std::hash<sgc::math::uval>{}(v.x)
                 ^ (std::hash<sgc::math::uval>{}(v.y) << 1)
                 ^ (std::hash<sgc::math::uval>{}(v.z) << 2)
                 ^ (std::hash<sgc::math::uval>{}(v.w) << 3);
        }
    };

    template<>
    struct  hash<sgc::math::fvec4>
    {
        size_t operator()(const sgc::math::fvec4& v) const noexcept
        {
            return std::hash<float>{}(v.x)
                 ^ (std::hash<float>{}(v.y) << 1)
                 ^ (std::hash<float>{}(v.z) << 2)
                 ^ (std::hash<float>{}(v.w) << 3);
        }
    };

}