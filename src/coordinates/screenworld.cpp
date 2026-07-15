#include "sgc/coordinates/screenworld.hpp"

sgc::math::fvec2 sgc::coordinates::ScreenToWorld(sgc::math::fvec2 position, const graphics::View view)
{
    return {
        (position.x - view.screen.x) * view.camera.w / view.screen.w + view.camera.x,
        (position.y - view.screen.y) * view.camera.h / view.screen.h + view.camera.y
    };
}

sgc::math::fvec2 sgc::coordinates::WorldToScreen(sgc::math::fvec2 position, const graphics::View view)
{
    return {
        (position.x - view.camera.x) * view.screen.w / view.camera.w + view.screen.x,
        (position.y - view.camera.y) * view.screen.h / view.camera.h + view.screen.y
    };
}