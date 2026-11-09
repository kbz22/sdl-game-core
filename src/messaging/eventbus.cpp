#include "sgc/messaging/eventbus.hpp"
#include <functional>
#include <deque>

using   sgc::messaging::TypeId,
        sgc::messaging::SubscriptionId,
        sgc::messaging::EventBus,
        sgc::messaging::Subscription,
        sgc::messaging::Event;

template<Event E> 
struct EventBus::Channel : public EventBus::ChannelBase
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

Subscription::Subscription(EventBus *bus, TypeId type, SubscriptionId id) :
    m_bus{bus},
    m_type{type},
    m_id{id}
{}

inline void Subscription::reset()
{
    m_bus->Unsubscribe(m_type, m_id);
    // m_bus.reset();
    m_bus = nullptr;
}

static TypeId NextTypeId()
{
    static TypeId count = 0;
    return count++;
}

template<Event E>
static TypeId EventBus::GetTypeId()
{
    static const TypeId id = NextTypeId();
    return id;
}

template<Event E>
EventBus::Channel<E>& EventBus::GetChannel()
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

void EventBus::Unsubscribe(TypeId type, SubscriptionId id)
{
    if(type < m_channels.size())
    {
        m_channels[type]->Remove(id);
    }    
}

template <Event E, std::invocable<const E&> F>
Subscription EventBus::Subscribe(F&& handler)
{
    return {
        this,
        GetTypeId<E>(),
        GetChannel<E>()->Add(handler)
    };
}