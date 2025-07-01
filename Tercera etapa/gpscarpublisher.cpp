#include "gpscarpublisher.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QVBoxLayout>
#include <QString>

GPSCarPublisher::GPSCarPublisher(const QString& name,
                                 const QString& topic,
                                 QWidget* parent)
    : QWidget(parent),
    Publisher(name.toStdString(), topic.toStdString()),
    m_timer(new QTimer(this)),
    m_currentTime(0),
    m_index(0)
{
    m_selectBtn = new QPushButton("Seleccionar archivo GPS...", this);
    auto *lay = new QVBoxLayout(this);
    lay->addWidget(m_selectBtn);
    setLayout(lay);

    connect(m_selectBtn, &QPushButton::clicked,
            this, &GPSCarPublisher::onSelectFile);
    connect(m_timer, &QTimer::timeout,
            this, &GPSCarPublisher::onTimeout);
}

void GPSCarPublisher::onSelectFile() {
    QString path = QFileDialog::getOpenFileName(
        this,
        "Seleccione archivo de posiciones",
        "",
        "Text Files (*.txt);;All Files (*)"
        );
    if (path.isEmpty()) return;

    QFile file(path);
    if (!file.open(QFile::ReadOnly | QFile::Text)) return;

    QTextStream in(&file);
    m_times.clear();
    m_positions.clear();
    while (!in.atEnd()) {
        double t, x, y;
        in >> t >> x >> y;
        if (in.status() == QTextStream::Ok) {
            m_times.push_back(t);
            m_positions.emplace_back(x, y);
        }
    }
    file.close();

    if (m_times.size() < 2) return;

    m_currentTime = m_times.front();
    m_index = 0;

    // Avisamos que ya cargó el archivo: la ventana del seguidor puede mostrarse
    emit fileSelected();

    // Arrancamos la publicación cada segundo
    m_timer->start(1000);
}

void GPSCarPublisher::onTimeout() {
    if (m_index >= int(m_times.size()) - 1) {
        m_timer->stop();
        return;
    }

    double t0 = m_times[m_index];
    double t1 = m_times[m_index + 1];
    if (m_currentTime > t1) {
        m_index++;
        t0 = m_times[m_index];
        if (m_index + 1 < int(m_times.size()))
            t1 = m_times[m_index + 1];
    }

    double ratio = (m_currentTime - t0) / (t1 - t0);
    const QPointF &p0 = m_positions[m_index];
    const QPointF &p1 = m_positions[m_index + 1];
    double x = p0.x() + ratio * (p1.x() - p0.x());
    double y = p0.y() + ratio * (p1.y() - p0.y());

    QString msg = QString("%1 %2 %3")
                      .arg(m_currentTime)
                      .arg(x)
                      .arg(y);
    publish(msg.toStdString());

    m_currentTime += 1.0;
}
