#include "sgc/math/vector.hpp"

sgc::math::fvec2 sgc::math::Normalize(const sgc::math::fvec2& vec)
{
    float length = std::sqrt(vec.x * vec.x + vec.y * vec.y);
    if (length == 0.0f) {
        return { 0.0f, 0.0f }; // Return a zero vector if the input vector has zero length
    }
    return { vec.x / length, vec.y / length };
}

sgc::math::fvec3 sgc::math::Normalize(const sgc::math::fvec3& vec)
{
    float length = std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    if (length == 0.0f) {
        return { 0.0f, 0.0f, 0.0f }; // Return a zero vector if the input vector has zero length
    }
    return { vec.x / length, vec.y / length, vec.z / length };
}

sgc::math::fvec4 sgc::math::Normalize(const sgc::math::fvec4& vec)
{
    float length = std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w);
    if (length == 0.0f) {
        return { 0.0f, 0.0f, 0.0f, 0.0f }; // Return a zero vector if the input vector has zero length
    }
    return { vec.x / length, vec.y / length, vec.z / length, vec.w / length };
}

float sgc::math::VectorLength(const sgc::math::fvec2& vec)
{
    return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}

float sgc::math::VectorLength(const sgc::math::fvec3& vec)
{
    return std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

float sgc::math::VectorLength(const sgc::math::fvec4& vec)
{
    return std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w);
}