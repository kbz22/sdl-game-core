#pragma once

#include "sgc/graphics/viewport.hpp"
#include "sgc/math/vector.hpp"

namespace sgc::coordinates {

    math::fvec2 ScreenToWorld(math::fvec2 position, const graphics::View view);
    math::fvec2 WorldToScreen(math::fvec2 position, const graphics::View view);
    float ScreenToWorld(float value, const graphics::View view);
    float WorldToScreen(float value, const graphics::View view);

}