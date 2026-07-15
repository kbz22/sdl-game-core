#pragma once

#include <cstdint>
#include <functional>

namespace sgc::math {

    using ival = int64_t;
    using uval = uint64_t;        

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
}