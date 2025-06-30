#include "videofollower.h"
#include "videoplayerwindow.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QUrl>

VideoFollower::VideoFollower(const QString& name,
                             const QString& topic,
                             QWidget* parent)
    : QWidget(parent),
    Subscriber(name.toStdString(), topic.toStdString())
{
    m_button = new QPushButton("Sin publicación", this);
    m_button->setEnabled(false);

    auto* lay = new QVBoxLayout(this);
    lay->addWidget(m_button);
    setLayout(lay);

    connect(m_button, &QPushButton::clicked,
            this, &VideoFollower::onPlay);
}

void VideoFollower::update(const std::string& message) {
    m_lastUrl = QUrl::fromLocalFile(QString::fromStdString(message));
    if (!m_lastUrl.isLocalFile())
        m_lastUrl = QUrl(QString::fromStdString(message));

    m_button->setText(m_lastUrl.path());
    m_button->setEnabled(true);
}

void VideoFollower::onPlay() {
    auto* playerWin = new VideoPlayerWindow(m_lastUrl, this);
    playerWin->show();
}

