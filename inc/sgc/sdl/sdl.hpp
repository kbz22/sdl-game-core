#pragma once

#include <SDL3/SDL.h>

#include "sgc/messaging/message_queue.hpp"
#include "sgc/types.hpp"

namespace sgc::sdl {

    bool InitVideo();

    void Shutdown();

    SDL_Window* CreateWindow(const char* title, int width, int height, SDL_WindowFlags flags = SDL_WINDOW_RESIZABLE);        

    SDL_Renderer* CreateRenderer(SDL_Window* window);

    void DestroyRenderer(SDL_Renderer* renderer);

    void DestroyWindow(SDL_Window* window);

    void Clear(SDL_Renderer* renderer, graphics::color color);

    void Render(SDL_Renderer* renderer);    

    // void PollEvents(messaging::MessageQueue& messageQueue);

}