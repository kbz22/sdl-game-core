#pragma once

#include <cstdint>
#include <concepts>
#include <SDL3/SDL_scancode.h>

namespace sgc::messaging
{
    class EventBus;

    void PollSdl(EventBus &bus);

    using TypeId = size_t;
    using SubscriptionId = std::uint64_t;
    
    // Any plain, copyable struct can be an event.
    template <class E>
    concept Event = std::is_class_v<E> && std::copy_constructible<E>;

    //Events
    struct QuitRequestedEvent{};
}