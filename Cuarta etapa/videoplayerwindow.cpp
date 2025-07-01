#include "videoplayerwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QVideoWidget>
#include <QPushButton>
#include <QCloseEvent>
#include <QSlider>
#include <QUrl>

VideoPlayerWindow::VideoPlayerWindow(const QUrl& videoUrl,
                                     QWidget* parent)
    : QDialog(parent),
    m_isPlaying(false)
{
    setWindowTitle("Video Publicado");
    resize(800, 600);

    // Destruye en caso de cerrar la ventana
    setAttribute(Qt::WA_DeleteOnClose);

    // Multimedia
    m_player = new QMediaPlayer(this);
    m_audio  = new QAudioOutput(this);
    m_player->setAudioOutput(m_audio);

    // Video
    m_videoWidget = new QVideoWidget(this);
    m_player->setVideoOutput(m_videoWidget);

    // Botones
    m_playPauseBtn = new QPushButton("Play", this);
    m_stopBtn      = new QPushButton("Reiniciar", this);
    m_fwdBtn       = new QPushButton(">> 5s", this);
    m_bwdBtn       = new QPushButton("<< 10s", this);
    m_volSlider    = new QSlider(Qt::Horizontal, this);
    m_volSlider->setRange(0, 100);
    m_volSlider->setValue(80);

    // Layout
    auto* controlLay = new QHBoxLayout;
    controlLay->addWidget(m_playPauseBtn);
    controlLay->addWidget(m_stopBtn);
    controlLay->addWidget(m_bwdBtn);
    controlLay->addWidget(m_fwdBtn);
    controlLay->addWidget(m_volSlider);

    auto* mainLay = new QVBoxLayout(this);
    mainLay->addWidget(m_videoWidget);
    mainLay->addLayout(controlLay);
    setLayout(mainLay);

    connect(m_playPauseBtn, &QPushButton::clicked,
            this, &VideoPlayerWindow::onPlayPause);
    connect(m_stopBtn, &QPushButton::clicked,
            this, &VideoPlayerWindow::onStop);
    connect(m_fwdBtn, &QPushButton::clicked,
            this, &VideoPlayerWindow::onForward);
    connect(m_bwdBtn, &QPushButton::clicked,
            this, &VideoPlayerWindow::onBackward);
    connect(m_volSlider, &QSlider::valueChanged,
            this, &VideoPlayerWindow::onVolumeChanged);

    m_player->setSource(videoUrl);
    m_audio->setVolume(m_volSlider->value()/100.0);
}

void VideoPlayerWindow::closeEvent(QCloseEvent* event) {
    if (m_player) {
        m_player->stop();
    }
    QDialog::closeEvent(event);
}

void VideoPlayerWindow::onPlayPause() {
    if (!m_isPlaying) {
        m_player->play();
        m_playPauseBtn->setText("Pause");
    } else {
        m_player->pause();
        m_playPauseBtn->setText("Play");
    }
    m_isPlaying = !m_isPlaying;
}

void VideoPlayerWindow::onStop() {
    m_player->stop();
    m_playPauseBtn->setText("Play");
    m_isPlaying = false;
}

void VideoPlayerWindow::onForward() {
    m_player->setPosition(m_player->position() + 5000); // +5 s
}

void VideoPlayerWindow::onBackward() {
    qint64 pos = m_player->position() - 10000;           // –10 s
    m_player->setPosition(pos < 0 ? 0 : pos);
}

void VideoPlayerWindow::onVolumeChanged(int value) {
    m_audio->setVolume(value / 100.0);
}
