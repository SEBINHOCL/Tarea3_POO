#ifndef TOPIC_H
#define TOPIC_H

#include <string>

class Subscriber;

class Topic {
public:
    Topic(const std::string& name);
    void subscribe(Subscriber* subscriber);
    void publish(const std::string& message);

    std::string getName() const;

private:
    std::string m_name;
    Subscriber* m_subscriber;
};

#endif
