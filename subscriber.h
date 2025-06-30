#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "component.h"

class Subscriber : public Component {
public:
    Subscriber(const std::string& name, const std::string& topic);
    virtual ~Subscriber() = default;
    virtual void update(const std::string& message) = 0;
};

#endif
