#include "sgc/sdl/sdl.hpp"

#include "sgc/debug/log.hpp"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

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
    else {
        auto name = SDL_GetRendererName(renderer);
        debug::log(debug::LogMessage("SDL renderer:" + std::string(name)));
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

void sgc::sdl::Clear(graphics::RenderContext const& context, sgc::graphics::color color)
{
    if (!context.renderer) {
        return;
    }

    SDL_SetRenderDrawColor(context.renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(context.renderer);
}

void sgc::sdl::Render(graphics::RenderContext const& context)
{
    if (!context.renderer) {
        return;
    }

    SDL_RenderPresent(context.renderer);
}

void sgc::sdl::RenderAsImage(std::filesystem::path const& imagePath, graphics::RenderContext const& context, std::function<void(graphics::RenderContext const&)> renderFunction)
{
    if (!context.renderer) {
        return;
    }

    auto mapWidthPixels = static_cast<int>(context.view.screen.w);
    auto mapHeightPixels = static_cast<int>(context.view.screen.h);

    SDL_Texture* targetTexture = SDL_CreateTexture(
        context.renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET,
        mapWidthPixels,
        mapHeightPixels
    );

    SDL_SetRenderTarget(context.renderer, targetTexture);
    renderFunction(context);

    SDL_Surface* surface = SDL_RenderReadPixels(context.renderer, nullptr);

    SDL_SetRenderTarget(context.renderer, nullptr);

    IMG_SavePNG(surface, imagePath.string().c_str());
    SDL_DestroyTexture(targetTexture);
    SDL_DestroySurface(surface);
}

/* void sgc::sdl::PollEvents(messaging::MessageQueue& messageQueue)
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
} */