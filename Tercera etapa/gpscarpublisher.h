#ifndef GPSCARPUBLISHER_H
#define GPSCARPUBLISHER_H

#include "publisher.h"
#include <QWidget>
#include <QPushButton>
#include <QTimer>
#include <QPointF>
#include <vector>

class GPSCarPublisher : public QWidget, public Publisher {
    Q_OBJECT
public:
    GPSCarPublisher(const QString& name,
                    const QString& topic,
                    QWidget* parent = nullptr);

signals:
    void fileSelected();

private slots:
    void onSelectFile();
    void onTimeout();

private:
    QPushButton*            m_selectBtn;
    QTimer*                 m_timer;
    std::vector<double>     m_times;
    std::vector<QPointF>    m_positions;
    double                  m_currentTime;
    int                     m_index;
};

#endif
