#include "sdl/sdl_win32.hpp"

#ifdef _MSVC_LANG

SDL_Window* sgc::sdl::CreateWindowWin32(HWND hwnd, int width, int height){

    SDL_PropertiesID properties = SDL_CreateProperties();
    SDL_Window* sdlWindow = nullptr;

    if (properties == 0) {
        return nullptr;
    }

    SDL_SetPointerProperty(properties, SDL_PROP_WINDOW_CREATE_WIN32_HWND_POINTER, hwnd);
    SDL_SetNumberProperty(properties, SDL_PROP_WINDOW_CREATE_WIDTH_NUMBER, width);
    SDL_SetNumberProperty(properties, SDL_PROP_WINDOW_CREATE_HEIGHT_NUMBER, height);
    SDL_SetBooleanProperty(properties, SDL_PROP_WINDOW_CREATE_BORDERLESS_BOOLEAN, true);

    sdlWindow = SDL_CreateWindowWithProperties(properties);
    SDL_DestroyProperties(properties);

    if (sdlWindow == nullptr) {
        return nullptr;
    }

    return sdlWindow;
}

HWND sgc::sdl::GetWin32HWND(SDL_Window* window){
    SDL_PropertiesID props = SDL_GetWindowProperties(window);
    void* native = SDL_GetPointerProperty(props, SDL_PROP_WINDOW_WIN32_HWND_POINTER, nullptr);
    
    return static_cast<HWND>(native);
}

#endif