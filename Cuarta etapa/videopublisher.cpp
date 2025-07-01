#include "videopublisher.h"
#include <QLineEdit>
#include <QHBoxLayout>

VideoPublisher::VideoPublisher(const QString& name,
                               const QString& topic,
                               QWidget* parent)
    : QWidget(parent),
    Publisher(name.toStdString(), topic.toStdString())
{
    m_lineEdit = new QLineEdit(this);
    auto* lay = new QHBoxLayout(this);
    lay->addWidget(m_lineEdit);
    setLayout(lay);

    connect(m_lineEdit, &QLineEdit::returnPressed,
            this, &VideoPublisher::onReturnPressed);
}

void VideoPublisher::onReturnPressed() {
    const QString text = m_lineEdit->text().trimmed();
    if (!text.isEmpty()) {
        publish(text.toStdString());
        m_lineEdit->clear();
    }
}
