#ifndef VIDEOFOLLOWER_H
#define VIDEOFOLLOWER_H

#include "subscriber.h"
#include <QWidget>

class QPushButton;

class VideoFollower : public QWidget, public Subscriber {
    Q_OBJECT
public:
    VideoFollower(const QString& name,
                  const QString& topic,
                  QWidget* parent = nullptr);

    void update(const std::string& message) override;

private slots:
    void onPlay();

private:
    QPushButton*   m_button;
    std::string    m_lastUrl;
};

#endif
