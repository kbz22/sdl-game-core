#pragma once

#include <SDL3/SDL.h>

#include "sgc/math/vector.hpp"
#include "sgc/graphics/color.hpp"
#include "sgc/graphics/rendercontext.hpp"

namespace sgc::sdl {

    bool InitVideo();

    void Shutdown();

    SDL_Window* CreateWindow(const char* title, int width, int height, SDL_WindowFlags flags = SDL_WINDOW_RESIZABLE);        

    SDL_Renderer* CreateRenderer(SDL_Window* window);

    void DestroyRenderer(SDL_Renderer* renderer);

    void DestroyWindow(SDL_Window* window);

    void Clear(graphics::RenderContext const& context, graphics::color color);

    void Render(graphics::RenderContext const& context);    

    // void PollEvents(messaging::MessageQueue& messageQueue);

}