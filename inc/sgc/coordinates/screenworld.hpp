#pragma once

#include "sgc/graphics/viewport.hpp"
#include "sgc/coordinates/position.hpp"

namespace sgc::coordinates 
{
    struct WorldType {};
    struct ScreenType {};

    using WorldPosition2D = SinglesPosition2D<WorldType>;
    using ScreenPosition = SinglesPosition2D<ScreenType>;

    WorldPosition2D ToWorld(ScreenPosition position, const graphics::View &view);
    ScreenPosition ToScreen(WorldPosition2D position, const graphics::View &view);
    float ScreenToWorld(float value, const graphics::View view);
    float WorldToScreen(float value, const graphics::View view);
}