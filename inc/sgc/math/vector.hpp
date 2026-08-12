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

        vec2 operator-(const vec2& other) const
        {
            return {
                x - other.x,
                y - other.y
            };
        }

        vec2 operator-=(const vec2& other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        vec2 operator+(const vec2& other) const
        {
            return {
                x + other.x,
                y + other.y
            };
        }

        vec2 operator+=(const vec2& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        vec2 operator*(ival scalar) const
        {
            return {
                x * scalar,
                y * scalar
            };
        }

        vec2 operator*=(ival scalar)
        {
            x *= scalar;
            y *= scalar;
            return *this;
        }
    };

    struct uvec2 {
        uval x;
        uval y;

        bool operator==(const uvec2& other) const noexcept
        {
            return x == other.x && y == other.y;
        }

        uvec2 operator-(const uvec2& other) const
        {
            return {
                x - other.x,
                y - other.y
            };
        }

        uvec2 operator-=(const uvec2& other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        uvec2 operator+(const uvec2& other) const
        {
            return {
                x + other.x,
                y + other.y
            };
        }

        uvec2 operator+=(const uvec2& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        uvec2 operator*(uval scalar) const
        {
            return {
                x * scalar,
                y * scalar
            };
        }

        uvec2 operator*=(uval scalar)
        {
            x *= scalar;
            y *= scalar;
            return *this;
        }
    };

    struct fvec2 {
        float x;
        float y;

        bool operator==(const fvec2& other) const noexcept
        {
            return x == other.x && y == other.y;
        }

        fvec2 operator-(const fvec2& other) const
        {
            return {
                x - other.x,
                y - other.y
            };
        }

        fvec2 operator-=(const fvec2& other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        fvec2 operator+(const fvec2& other) const
        {
            return {
                x + other.x,
                y + other.y
            };
        }

        fvec2 operator+=(const fvec2& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        fvec2 operator*(float scalar) const
        {
            return {
                x * scalar,
                y * scalar
            };
        }

        fvec2 operator*=(float scalar)
        {
            x *= scalar;
            y *= scalar;
            return *this;
        }
    };

    struct vec3 {
        ival x;
        ival y;
        ival z;

        bool operator==(const vec3& other) const noexcept
        {
            return x == other.x && y == other.y && z == other.z;
        }

        vec3 operator-(const vec3& other) const
        {
            return {
                x - other.x,
                y - other.y,
                z - other.z
            };
        }

        vec3 operator-=(const vec3& other)
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            return *this;
        }

        vec3 operator+(const vec3& other) const
        {
            return {
                x + other.x,
                y + other.y,
                z + other.z
            };
        }

        vec3 operator+=(const vec3& other)
        {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }

        vec3 operator*(ival scalar) const
        {
            return {
                x * scalar,
                y * scalar,
                z * scalar
            };
        }

        vec3 operator*=(ival scalar)
        {
            x *= scalar;
            y *= scalar;
            z *= scalar;
            return *this;
        }
    };

    struct uvec3 {
        uval x;
        uval y;
        uval z;

        bool operator==(const uvec3& other) const noexcept
        {
            return x == other.x && y == other.y && z == other.z;
        }

        uvec3 operator-(const uvec3& other) const
        {
            return {
                x - other.x,
                y - other.y,
                z - other.z
            };
        }

        uvec3 operator-=(const uvec3& other)
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            return *this;
        }

        uvec3 operator+(const uvec3& other) const
        {
            return {
                x + other.x,
                y + other.y,
                z + other.z
            };
        }

        uvec3 operator+=(const uvec3& other)
        {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }

        uvec3 operator*(uval scalar) const
        {
            return {
                x * scalar,
                y * scalar,
                z * scalar
            };
        }

        uvec3 operator*=(uval scalar)
        {
            x *= scalar;
            y *= scalar;
            z *= scalar;
            return *this;
        }
    };

    struct fvec3 {
        float x;
        float y;
        float z;

        bool operator==(const fvec3& other) const noexcept
        {
            return x == other.x && y == other.y && z == other.z;
        }

        fvec3 operator-(const fvec3& other) const
        {
            return {
                x - other.x,
                y - other.y,
                z - other.z
            };
        }

        fvec3 operator-=(const fvec3& other)
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            return *this;
        }

        fvec3 operator+(const fvec3& other) const
        {
            return {
                x + other.x,
                y + other.y,
                z + other.z
            };
        }

        fvec3 operator+=(const fvec3& other)
        {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }

        fvec3 operator*(float scalar) const
        {
            return {
                x * scalar,
                y * scalar,
                z * scalar
            };
        }

        fvec3 operator*=(float scalar)
        {
            x *= scalar;
            y *= scalar;
            z *= scalar;
            return *this;
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

        vec4 operator-(const vec4& other) const
        {
            return {
                x - other.x,
                y - other.y,
                z - other.z,
                w - other.w
            };
        }

        vec4 operator-=(const vec4& other)
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            w -= other.w;
            return *this;
        }

        vec4 operator+(const vec4& other) const
        {
            return {
                x + other.x,
                y + other.y,
                z + other.z,
                w + other.w
            };
        }

        vec4 operator+=(const vec4& other)
        {
            x += other.x;
            y += other.y;
            z += other.z;
            w += other.w;
            return *this;
        }

        vec4 operator*(ival scalar) const
        {
            return {
                x * scalar,
                y * scalar,
                z * scalar,
                w * scalar
            };
        }

        vec4 operator*=(ival scalar)
        {
            x *= scalar;
            y *= scalar;
            z *= scalar;
            w *= scalar;
            return *this;
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

        uvec4 operator-(const uvec4& other) const
        {
            return {
                x - other.x,
                y - other.y,
                z - other.z,
                w - other.w
            };
        }

        uvec4 operator-=(const uvec4& other)
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            w -= other.w;
            return *this;
        }

        uvec4 operator+(const uvec4& other) const
        {
            return {
                x + other.x,
                y + other.y,
                z + other.z,
                w + other.w
            };
        }

        uvec4 operator+=(const uvec4& other)
        {
            x += other.x;
            y += other.y;
            z += other.z;
            w += other.w;
            return *this;
        }

        uvec4 operator*(uval scalar) const
        {
            return {
                x * scalar,
                y * scalar,
                z * scalar,
                w * scalar
            };
        }

        uvec4 operator*=(uval scalar)
        {
            x *= scalar;
            y *= scalar;
            z *= scalar;
            w *= scalar;
            return *this;
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

        fvec4 operator-(const fvec4& other) const
        {
            return {
                x - other.x,
                y - other.y,
                z - other.z,
                w - other.w
            };
        }

        fvec4 operator-=(const fvec4& other)
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            w -= other.w;
            return *this;
        }

        fvec4 operator+(const fvec4& other) const
        {
            return {
                x + other.x,
                y + other.y,
                z + other.z,
                w + other.w
            };
        }

        fvec4 operator+=(const fvec4& other)
        {
            x += other.x;
            y += other.y;
            z += other.z;
            w += other.w;
            return *this;
        }

        fvec4 operator*(float scalar) const
        {
            return {
                x * scalar,
                y * scalar,
                z * scalar,
                w * scalar
            };
        }
        
        fvec4 operator*=(float scalar)
        {
            x *= scalar;
            y *= scalar;
            z *= scalar;
            w *= scalar;
            return *this;
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

namespace sgc::math {

    fvec2 Normalize(const fvec2& vec);
    fvec3 Normalize(const fvec3& vec);
    fvec4 Normalize(const fvec4& vec);

    float VectorLength(const fvec2& vec);
    float VectorLength(const fvec3& vec);
    float VectorLength(const fvec4& vec);

}