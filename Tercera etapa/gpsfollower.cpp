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

    // 1) Creamos la escena y el círculo (radio 15)
    m_scene = new QGraphicsScene(this);
    m_car = new QGraphicsEllipseItem(-15, -15, 30, 30);
    m_car->setBrush(Qt::red);
    m_scene->addItem(m_car);

    // 2) Vista para la escena
    m_view = new QGraphicsView(m_scene, this);
    m_view->setRenderHint(QPainter::Antialiasing);
    m_view->setSceneRect(0, 0, 400, 400);  // Ajusta a tus coordenadas máximas

    // 3) Layout
    auto* lay = new QVBoxLayout(this);
    lay->addWidget(m_view);
    setLayout(lay);

    // 4) Tamaño inicial de la ventana
    resize(420, 440);
}

void GPSFollower::update(const std::string& message)
{
    Q_UNUSED(message);
}
