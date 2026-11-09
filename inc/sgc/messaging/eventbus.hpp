#pragma once

#include "sgc/messaging/event.hpp"
#include <vector>
#include <memory>

namespace sgc::messaging
{
    class Subscription 
    {
        private:
            EventBus *m_bus = nullptr;
            TypeId m_type = 0;
            SubscriptionId m_id = 0;

            Subscription(EventBus *bus, TypeId type, SubscriptionId id);

        public:
            Subscription() = default;
            Subscription(const Subscription&) = delete;
            Subscription& operator=(const Subscription&) = delete;
            ~Subscription();

            void reset();

        friend class EventBus;
    };

    class EventBus
    {
        private:
            // type-erased base so channels of different E live in one container.
            struct ChannelBase {
                virtual ~ChannelBase() = default;
                virtual void Flush() = 0;
                virtual void Remove(SubscriptionId id) = 0;
            };

            template<Event E>
            struct Channel;

            template<Event E>
            static TypeId GetTypeId();

            template<Event E>
            Channel<E>& GetChannel();
        
            std::vector<std::unique_ptr<ChannelBase>> m_channels;

            void Unsubscribe(TypeId type, SubscriptionId id);

        public:
            EventBus() = default;
            ~EventBus() = default;
            EventBus(const EventBus&) = delete;
            EventBus& operator=(const EventBus&) = delete;
            EventBus(EventBus&&) = delete;
            EventBus& operator=(EventBus&&) = delete;

            template <Event E, std::invocable<const E&> F>
            [[nodiscard]] Subscription Subscribe(F&& handler);
                    
            template <Event E>
            void Post(E event);
        
            // if the call must be synchronous.
            template <Event E>
            void DispatchNow(const E& event);

            void Flush();
        
            friend class Subscription;
        };

}