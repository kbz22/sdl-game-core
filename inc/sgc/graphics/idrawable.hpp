#pragma once

#include <SDL3/SDL.h>
#include <memory>

#include "sgc/graphics/viewport.hpp"

namespace sgc::graphics {

    struct RenderContext {
        SDL_Renderer* renderer;
        View view;
    };

    class IDrawable {
        public:
            virtual ~IDrawable() = default;
            virtual void Draw(const RenderContext& context) = 0;            
    };

}