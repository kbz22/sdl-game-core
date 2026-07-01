#pragma once

#include <cstdint>
#include <functional>

namespace sgc::math {

    using i64 = int64_t;
    using u64 = uint64_t;

    struct vec2 {
        i64 x;
        i64 y;

        bool operator==(const vec2& other) const noexcept
        {
            return x == other.x && y == other.y;
        }
    };

    struct uvec2 {
        u64 x;
        u64 y;

        bool operator==(const uvec2& other) const noexcept
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
            return std::hash<sgc::math::u64>{}(v.x)
                 ^ (std::hash<sgc::math::u64>{}(v.y) << 1);
        }
    };

    template<>
    struct hash<sgc::math::vec2>
    {
        size_t operator()(const sgc::math::vec2& v) const noexcept
        {
            return std::hash<sgc::math::i64>{}(v.x)
                 ^ (std::hash<sgc::math::i64>{}(v.y) << 1);
        }
    };
}