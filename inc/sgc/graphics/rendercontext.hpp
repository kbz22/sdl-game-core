#pragma once

#include <SDL3/SDL.h>
#include <sgc/graphics/viewport.hpp>

namespace sgc::graphics {

    struct RenderContext {
        SDL_Renderer* renderer;
        View view;
    };

}