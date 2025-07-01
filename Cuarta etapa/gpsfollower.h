#ifndef GPSFOLLOWER_H
#define GPSFOLLOWER_H

#include "subscriber.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>

class GPSFollower : public QWidget, public Subscriber {
    Q_OBJECT
public:
    GPSFollower(const QString& name,
                const QString& topic,
                QWidget* parent = nullptr);

    void update(const std::string& message) override;

private:
    QGraphicsScene*         m_scene;
    QGraphicsView*          m_view;
    QGraphicsEllipseItem*   m_car;
};

#endif
