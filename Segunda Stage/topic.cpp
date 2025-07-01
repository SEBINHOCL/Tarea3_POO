#include "topic.h"
#include "subscriber.h"

Topic::Topic(const std::string& name) : m_name(name), m_subscriber(nullptr) {}

void Topic::subscribe(Subscriber* subscriber) {
    m_subscriber = subscriber;
}

void Topic::publish(const std::string& message) {
    if (m_subscriber) {
        m_subscriber->update(message);
    }
}

std::string Topic::getName() const {
    return m_name;
}
