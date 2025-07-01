#ifndef VIDEOPUBLISHER_H
#define VIDEOPUBLISHER_H

#include "publisher.h"
#include <QWidget>

class QLineEdit;
class QPushButton;

class VideoPublisher : public QWidget, public Publisher {
    Q_OBJECT
public:
    VideoPublisher(const QString& name,
                   const QString& topic,
                   QWidget* parent = nullptr);

private slots:
    void onPublish();

private:
    QLineEdit*    m_lineEdit;
    QPushButton*  m_publishBtn;
};

#endif
