#include "gpsfollower.h"
#include <QVBoxLayout>
#include <QString>
#include <sstream>
#include <QPainter>

GPSFollower::GPSFollower(const QString& name,
                         const QString& topic,
                         QWidget* parent)
    : QWidget(parent),
    Subscriber(name.toStdString(), topic.toStdString())
{
    setWindowTitle("Seguidor GPS: " + name);

    m_scene = new QGraphicsScene(this);
    m_car = new QGraphicsEllipseItem(-15, -15, 30, 30);
    m_car->setBrush(Qt::red);
    m_scene->addItem(m_car);

    m_view = new QGraphicsView(m_scene, this);
    m_view->setRenderHint(QPainter::Antialiasing);
    m_view->setSceneRect(0, 0, 400, 400);

    // Layout
    auto* lay = new QVBoxLayout(this);
    lay->addWidget(m_view);
    setLayout(lay);

    // Tamaño inicial de la ventana
    resize(420, 440);
}

void GPSFollower::update(const std::string& message) {

    std::istringstream iss(message);
    double t, x, y;
    if (!(iss >> t >> x >> y)) return;

    m_car->setPos(x, y);
}
