#include "sgc/coordinates/screenworld.hpp"

using sgc::coordinates::WorldPosition2D, sgc::coordinates::ScreenPosition;

WorldPosition2D sgc::coordinates::ToWorld(ScreenPosition position, const graphics::View &view)
{
    return {
        (position.x - view.screen.x) * view.camera.w / view.screen.w + view.camera.x,
        (position.y - view.screen.y) * view.camera.h / view.screen.h + view.camera.y
    };
}

ScreenPosition sgc::coordinates::ToScreen(WorldPosition2D position, const graphics::View &view)
{
    return {
        (position.x - view.camera.x) * view.screen.w / view.camera.w + view.screen.x,
        (position.y - view.camera.y) * view.screen.h / view.camera.h + view.screen.y
    };
}

float sgc::coordinates::ScreenToWorld(float value, const graphics::View view)
{
    return (value - view.screen.x) * view.camera.w / view.screen.w + view.camera.x;
}

float sgc::coordinates::WorldToScreen(float value, const graphics::View view)
{
    return (value - view.camera.x) * view.screen.w / view.camera.w + view.screen.x;
}