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

            case SDL_EVENT_KEY_DOWN:
            {
                SDL_Keycode keycode = event.key.key;
                KeyboardInput event{};

                switch(keycode)
                {
                    case SDLK_UP:
                    {
                        event.key = KeyboardKey::Up;
                        break;
                    }

                    case SDLK_DOWN:
                    {
                        event.key = KeyboardKey::Down;
                        break;
                    }

                    case SDLK_LEFT:
                    {
                        event.key = KeyboardKey::Left;
                        break;
                    }

                    case SDLK_RIGHT:
                    {
                        event.key = KeyboardKey::Right;
                        break;
                    }

                    case SDLK_RETURN:
                    {
                        event.key = KeyboardKey::Enter;
                        break;
                    }

                    case SDLK_ESCAPE:
                    {
                        event.key = KeyboardKey::Escape;
                        break;
                    }

                    case SDLK_SPACE:
                    {
                        event.key = KeyboardKey::Space;
                        break;
                    }

                    default:
                    {
                        if ((keycode >= SDLK_A && keycode <= SDLK_Z)) 
                        {
                            event.key = KeyboardKey::Letter;
                        }
                        else if ((keycode >= SDLK_0 && keycode <= SDLK_9)) 
                        {
                            event.key = KeyboardKey::Number;
                        }
                        break;
                    }
                }

                if(event.key != KeyboardKey::Undefined)
                {
                    eventBus.Post<KeyboardInput>(event);
                }

                break;
            }

            default:
            {
                break;
            }
        }
    }
}