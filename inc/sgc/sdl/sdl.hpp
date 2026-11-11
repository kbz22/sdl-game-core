#pragma once

#include <SDL3/SDL.h>
#include <filesystem>
#include <functional>

#include "sgc/graphics/color.hpp"
#include "sgc/graphics/rendercontext.hpp"
#include "sgc/messaging/eventbus.hpp"

namespace sgc::sdl {

    bool InitVideo();

    void Shutdown();

    SDL_Window* CreateWindow(const char* title, int width, int height, SDL_WindowFlags flags = SDL_WINDOW_RESIZABLE);

    SDL_Renderer* CreateRenderer(SDL_Window* window);

    void DestroyRenderer(SDL_Renderer* renderer);

    void DestroyWindow(SDL_Window* window);

    void Clear(graphics::RenderContext const& context, graphics::color color);

    void Render(graphics::RenderContext const& context);

    void RenderAsImage(std::filesystem::path const &imagePath, graphics::RenderContext const &context, std::function<void(graphics::RenderContext const&)> renderFunction);

    void PollSdlEvents(sgc::messaging::EventBus &bus);

}