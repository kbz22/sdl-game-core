#include "sgc/messaging/eventbus.hpp"
#include <functional>
#include <deque>

using   sgc::messaging::TypeId,
        sgc::messaging::SubscriptionId,
        sgc::messaging::EventBus,
        sgc::messaging::Subscription,
        sgc::messaging::Event;

Subscription::Subscription(EventBus *bus, TypeId type, SubscriptionId id) :
    m_bus{bus},
    m_type{type},
    m_id{id}
{}

Subscription::~Subscription()
{
    this->reset();
}

inline void Subscription::reset()
{
    m_bus->Unsubscribe(m_type, m_id);    
    m_bus = nullptr;
}

TypeId EventBus::NextTypeId()
{
    static TypeId count = 0;
    return count++;
}

void EventBus::Unsubscribe(TypeId type, SubscriptionId id)
{
    if(type < m_channels.size())
    {
        m_channels[type]->Remove(id);
    }    
}