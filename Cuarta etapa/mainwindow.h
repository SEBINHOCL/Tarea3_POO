#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class VideoPublisher;
class VideoFollower;
class GPSCarPublisher;
class GPSFollower;

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    VideoPublisher*   m_videoPub;
    VideoFollower*    m_videoSub;
    GPSCarPublisher*  m_gpsPub;
    GPSFollower*      m_gpsSub;
};

#endif
