#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "videopublisher.h"
#include "videofollower.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_videoPub(nullptr)
    , m_videoSub(nullptr)
{
    ui->setupUi(this);

    // Layout principal
    QWidget* central = ui->centralwidget;
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

