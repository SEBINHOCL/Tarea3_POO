#ifndef VIDEOPLAYERWINDOW_H
#define VIDEOPLAYERWINDOW_H

#include <QDialog>
#include <QMediaPlayer>
#include <QAudioOutput>

class QVideoWidget;
class QPushButton;
class QSlider;

class VideoPlayerWindow : public QDialog {
    Q_OBJECT
public:
    explicit VideoPlayerWindow(const QUrl& videoUrl,
                               QWidget* parent = nullptr);
    ~VideoPlayerWindow() override = default;

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void onPlayPause();
    void onStop();
    void onForward();
    void onBackward();
    void onVolumeChanged(int value);

private:
    QMediaPlayer*   m_player;
    QAudioOutput*   m_audio;
    QVideoWidget*   m_videoWidget;
    QPushButton*    m_playPauseBtn;
    QPushButton*    m_stopBtn;
    QPushButton*    m_fwdBtn;
    QPushButton*    m_bwdBtn;
    QSlider*        m_volSlider;
    bool            m_isPlaying;
};

#endif
