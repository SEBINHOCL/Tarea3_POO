#include "videopublisher.h"
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>

VideoPublisher::VideoPublisher(const QString& name,
                               const QString& topic,
                               QWidget* parent)
    : QWidget(parent),
    Publisher(name.toStdString(), topic.toStdString())
{
    m_lineEdit   = new QLineEdit(this);
    m_publishBtn = new QPushButton("Publicar", this);

    auto* lay = new QHBoxLayout(this);
    lay->addWidget(m_lineEdit);
    lay->addWidget(m_publishBtn);

    connect(m_publishBtn, &QPushButton::clicked,
            this, &VideoPublisher::onPublish);
}

void VideoPublisher::onPublish() {
    std::string url = m_lineEdit->text().toStdString();
    publish(url);
    m_lineEdit->clear();
}
