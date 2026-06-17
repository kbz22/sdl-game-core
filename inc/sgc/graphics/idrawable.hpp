#pragma once

#include <SDL3/SDL.h>
#include <memory>

namespace sgc::graphics {

    class IDrawable {
        public:
            virtual ~IDrawable() = default;
            virtual void Draw() = 0;
            virtual void SetRenderer(SDL_Renderer* renderer) = 0;
    };

}