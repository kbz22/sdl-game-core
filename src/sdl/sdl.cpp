#include "sdl/sdl.hpp"

#include "debug/log.hpp"

#include <SDL3/SDL.h>

bool sgc::sdl::InitVideo()
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        debug::log(debug::LogMessage("Failed to initialize SDL: " + std::string(SDL_GetError())));
        return false;
    }

    return true;
}

void sgc::sdl::Shutdown()
{
    SDL_Quit();
}

SDL_Window* sgc::sdl::CreateWindow(const char* title, int width, int height, SDL_WindowFlags flags)
{
    SDL_Window* window = SDL_CreateWindow(title, width, height, flags);
    if (!window) {
        debug::log(debug::LogMessage("Failed to create window: " + std::string(SDL_GetError())));
    }

    return window;
}

SDL_Renderer* sgc::sdl::CreateRenderer(SDL_Window* window)
{
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        debug::log(debug::LogMessage("Failed to create renderer: " + std::string(SDL_GetError())));
    }

    return renderer;
}

void sgc::sdl::DestroyRenderer(SDL_Renderer* renderer)
{
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
}

void sgc::sdl::DestroyWindow(SDL_Window* window)
{
    if (window) {
        SDL_DestroyWindow(window);
    }
}

void sgc::sdl::Clear(SDL_Renderer* renderer, sgc::graphics::color color)
{
    if (!renderer) {
        return;
    }

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}

void sgc::sdl::Render(SDL_Renderer* renderer)
{
    if (!renderer) {
        return;
    }

    SDL_RenderPresent(renderer);
}

void sgc::sdl::PollEvents(messaging::MessageQueue& messageQueue)
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {

            case SDL_EVENT_QUIT:
                {
                    messageQueue.Push(messaging::SystemEvent{ messaging::EventType::ProgramQuit });
                }
                break;

            case SDL_EVENT_KEY_DOWN:
                {
                    SDL_Keycode keycode = event.key.key;
                    types::KeyboardKey keyType = types::KeyboardKey::Other;
                    
                    if (keycode == SDLK_UP) {
                        keyType = types::KeyboardKey::Up;
                    }
                    else if (keycode == SDLK_DOWN) {
                        keyType = types::KeyboardKey::Down;
                    }
                    else if (keycode == SDLK_LEFT) {
                        keyType = types::KeyboardKey::Left;
                    }
                    else if (keycode == SDLK_RIGHT) {
                        keyType = types::KeyboardKey::Right;
                    }
                    else if (keycode == SDLK_RETURN) {
                        keyType = types::KeyboardKey::Enter;
                    }
                    else if (keycode == SDLK_ESCAPE) {
                        keyType = types::KeyboardKey::Escape;
                    }
                    else if (keycode == SDLK_SPACE) {
                        keyType = types::KeyboardKey::Space;
                    }
                    else if ((keycode >= SDLK_A && keycode <= SDLK_Z)) {
                        keyType = types::KeyboardKey::Letter;
                    }
                    else if ((keycode >= SDLK_0 && keycode <= SDLK_9)) {
                        keyType = types::KeyboardKey::Number;
                    }
                    
                    if (keyType != types::KeyboardKey::Other) {
                        messageQueue.Push(messaging::Event{ 
                            messaging::EventType::KeyboardPressed,
                            types::KeyboardEventPayload{ keyType, static_cast<uint32_t>(keycode) }
                        });
                    }
                }
                break;

            default:
                break;
        }
    }
}