#include "sgc/messaging/event.hpp"
#include "sgc/sdl/sdl.hpp"

using sgc::messaging::EventBus;

EventBus& sgc::messaging::GetEventBus()
{
    static EventBus eventBus{};
    return eventBus;
}

void sgc::sdl::PollSdlEvents(EventBus &bus)
{
    using namespace sgc::messaging;

    SDL_Event event;
    EventBus &eventBus = GetEventBus();

    while (SDL_PollEvent(&event)) {
        switch (event.type) {

            case SDL_EVENT_QUIT:
            {
                eventBus.Post<QuitRequestedEvent>(
                    QuitRequestedEvent{}
                );
                break;
            }

            default:
            {
                break;
            }
        }
    }
}