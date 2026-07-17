#pragma once

#ifdef _WIN32

#include <windows.h>
#include <SDL3/SDL.h>

// This is only for windows

namespace sgc::sdl {

    SDL_Window* CreateWindowWin32(HWND hwnd, int width, int height);
    HWND GetWin32HWND(SDL_Window* window);    

}

#else

#warning "This header is only for Windows targets only"

#endif