#include "component.h"

Component::Component(const std::string& name, const std::string& topic)
    : m_name(name), m_topic(topic)
{}

std::string Component::getName() const {
    return m_name;
}

std::string Component::getTopic() const {
    return m_topic;
}
