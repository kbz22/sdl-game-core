#pragma once

#include <cstdint>
#include <concepts>
#include <functional>

namespace sgc::messaging
{
    class EventBus;

    using TypeId = size_t;
    using SubscriptionId = std::uint64_t;
    
    // Any plain, copyable struct can be an event.
    template <class E>
    concept Event = std::is_class_v<E> && std::copy_constructible<E>;    

    //Events
    struct QuitRequestedEvent{};
}