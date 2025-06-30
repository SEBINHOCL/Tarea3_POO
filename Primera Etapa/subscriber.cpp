#include "subscriber.h"
#include "broker.h"

Subscriber::Subscriber(const std::string& name, const std::string& topic)
    : Component(name, topic)
{
    Broker::instance().subscribe(m_topic, this);
}
