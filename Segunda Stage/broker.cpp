#include "broker.h"
#include "subscriber.h"

Broker& Broker::instance() {
    static Broker inst;
    return inst;
}

void Broker::subscribe(const std::string& topic, Subscriber* sub) {
    m_subscribers[topic].push_back(sub);
}

void Broker::publish(const std::string& topic, const std::string& message) {
    auto it = m_subscribers.find(topic);
    if (it != m_subscribers.end()) {
        for (auto* sub : it->second) {
            sub->update(message);
        }
    }
}
