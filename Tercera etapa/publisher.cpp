#include "publisher.h"

Publisher::Publisher(const std::string& name, const std::string& topic)
    : Component(name, topic), m_broker(Broker::instance())
{}

void Publisher::publish(const std::string& message) {
    m_broker.publish(m_topic, message);
}
