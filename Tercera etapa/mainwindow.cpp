#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "gpscarpublisher.h"
#include "gpsfollower.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_gpsPub(nullptr)
    , m_gpsSub(nullptr)
{
    setWindowTitle("Simulador TareaPOO");
    ui->setupUi(this);

    auto* central   = ui->centralwidget;
    auto* mainLayout = new QHBoxLayout(central);
    central->setLayout(mainLayout);

    m_gpsPub = new GPSCarPublisher("GPSPub", "GPS", this);
    mainLayout->addWidget(m_gpsPub);

    // Creamos el seguidor GPS pero NO lo mostramos aún
    m_gpsSub = new GPSFollower("GPSSub", "GPS", nullptr);

    // Mostramos la ventana del seguidor **cuando** se selecciona el archivo
    connect(m_gpsPub, &GPSCarPublisher::fileSelected,
            m_gpsSub, &QWidget::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}
