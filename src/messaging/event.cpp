#include "sgc/messaging/event.hpp"
#include "sgc/messaging/eventbus.hpp"
#include <SDL3/SDL.h>

void sgc::messaging::PollSdl(EventBus &bus)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {

            case SDL_EVENT_QUIT:
            {
                
                break;
            }

            default:
                break;
        }
    }
}