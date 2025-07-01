#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    GPSCarPublisher*  m_gpsPub;
    GPSFollower*      m_gpsSub;
};

#endif
