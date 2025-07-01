#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "component.h"
#include "broker.h"

class Publisher : public Component {
public:
    Publisher(const std::string& name, const std::string& topic);
    virtual ~Publisher() = default;

protected:
    void publish(const std::string& message);
    Broker& m_broker;
};

#endif
