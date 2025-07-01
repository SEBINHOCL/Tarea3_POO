#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "videopublisher.h"
#include "videofollower.h"
#include "gpscarpublisher.h"
#include "gpsfollower.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_videoPub(nullptr)
    , m_videoSub(nullptr)
    , m_gpsPub(nullptr)
    , m_gpsSub(nullptr)
{
    setWindowTitle("Simulador Pub/Sub - Etapas 1 y 3");
    ui->setupUi(this);

    auto* central   = ui->centralwidget;
    auto* mainLayout = new QHBoxLayout(central);
    central->setLayout(mainLayout);

    auto* leftLayout  = new QVBoxLayout();
    auto* rightLayout = new QVBoxLayout();
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    m_videoPub = new VideoPublisher("VideoPub", "Video", this);
    m_videoSub = new VideoFollower("VideoSub", "Video", this);
    leftLayout->addWidget(m_videoPub);
    rightLayout->addWidget(m_videoSub);

    m_gpsPub = new GPSCarPublisher("GPSPub", "GPS", this);
    leftLayout->addWidget(m_gpsPub);

    m_gpsSub = new GPSFollower("GPSSub", "GPS", nullptr);

    connect(m_gpsPub, &GPSCarPublisher::fileSelected,
            m_gpsSub, &QWidget::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}
