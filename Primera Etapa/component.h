#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component {
public:
    Component(const std::string& name, const std::string& topic);
    virtual ~Component() = default;

    std::string getName() const;
    std::string getTopic() const;

protected:
    std::string m_name;
    std::string m_topic;
};

#endif
