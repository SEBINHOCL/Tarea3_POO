#include "videofollower.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QDesktopServices>
#include <QUrl>

VideoFollower::VideoFollower(const QString& name,
                             const QString& topic,
                             QWidget* parent)
    : QWidget(parent),
    Subscriber(name.toStdString(), topic.toStdString())
{
    m_button = new QPushButton("Sin publicacion", this);
    m_button->setEnabled(false);

    auto* lay = new QVBoxLayout(this);
    lay->addWidget(m_button);

    connect(m_button, &QPushButton::clicked,
            this, &VideoFollower::onPlay);
}

void VideoFollower::update(const std::string& message) {
    m_lastUrl = message;
    m_button->setText(QString::fromStdString(message));
    m_button->setEnabled(true);
}

void VideoFollower::onPlay() {

}
