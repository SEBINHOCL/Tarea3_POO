#ifndef BROKER_H
#define BROKER_H

#include <string>
#include <map>
#include <vector>

class Subscriber;

class Broker {
public:
    static Broker& instance();
    void subscribe(const std::string& topic, Subscriber* sub);
    void publish(const std::string& topic, const std::string& message);

private:
    Broker() = default;
    std::map<std::string, std::vector<Subscriber*>> m_subscribers;
};

#endif
