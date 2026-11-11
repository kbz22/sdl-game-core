#pragma once

#include "sgc/messaging/event.hpp"
#include <vector>
#include <memory>
#include <deque>

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
            struct Channel : public ChannelBase
            {
                struct Handler 
                {
                    TypeId id;
                    std::function<void(const E&)> fn;
                };

                std::deque<Handler> handlers; // deque: push_back() doesn't move existing elements
                std::vector<E> incoming;
                std::vector<E> processing;
                SubscriptionId nextId = 0;

                template<class F>
                SubscriptionId Add(F&& f)
                {
                    handlers.push_back({
                        nextId,
                        std::forward<F>(f)
                    });
                    return nextId++;
                }

                void Remove(std::size_t id) override
                {
                    for (auto& h : handlers)
                    {
                        if (h.id == id)
                        {
                            h.fn = nullptr;
                        }
                    }
                }

                void Deliver(const E& e)
                {
                    const std::size_t n = handlers.size(); // handlers added during dispatch wait until next event
                    for(std::size_t i = 0; i < n; ++i)
                    {
                        if (handlers[i].fn)
                        {
                            handlers[i].fn(e);
                        }
                    }
                }

                void Flush() override
                {
                    processing.swap(incoming);
                    for (const E& e : processing)
                    {
                        Deliver(e);
                    }

                    processing.clear();
                    std::erase_if(handlers, [](const Handler& h) 
                    {
                        return !h.fn;
                    });
                }
            };

            static TypeId NextTypeId();

            template<Event E>
            static TypeId GetTypeId()
            {
                static const TypeId id = NextTypeId();
                return id;
            }

            template<Event E>
            Channel<E>& GetChannel()
            {
                auto id = GetTypeId<E>();

                if(id >= m_channels.size())
                {
                    m_channels.resize(id+1);
                }

                if(!m_channels[id])
                {
                    m_channels[id] = std::make_unique<Channel<E>>();
                }

                return static_cast<Channel<E>&>(*m_channels[id]);
            }
        
            std::vector<std::unique_ptr<ChannelBase>> m_channels;

            void Unsubscribe(TypeId type, SubscriptionId id);

        public:
            EventBus() = default;
            ~EventBus() = default;
            EventBus(const EventBus&) = delete;
            EventBus& operator=(const EventBus&) = delete;
            EventBus(EventBus&&) = delete;
            EventBus& operator=(EventBus&&) = delete;

            template<Event E, std::invocable<const E&> F>
            [[nodiscard]] Subscription Subscribe(F&& handler)
            {
                return {
                    this,
                    GetTypeId<E>(),
                    GetChannel<E>().Add(handler)
                };
            }
                    
            template<Event E>
            void Post(E event)
            {
                GetChannel<E>().Deliver(event);
            }
        
            // if the call must be synchronous.
            template<Event E>
            void DispatchNow(const E& event);

            void Flush();
        
            friend class Subscription;
    };

    EventBus& GetEventBus();
}