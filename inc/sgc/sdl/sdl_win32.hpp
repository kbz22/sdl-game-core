#pragma once

#ifdef _MSVC_LANG

#include <windows.h>
#include <SDL3/SDL.h>

#warning "This header is only for windows targets."
// This is only for windows

namespace sgc::sdl {

    SDL_Window* CreateWindowWin32(HWND hwnd, int width, int height);
    HWND GetWin32HWND(SDL_Window* window);    

}

#endif