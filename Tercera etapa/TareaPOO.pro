QT       += core gui widgets multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    broker.cpp \
    component.cpp \
    gpscarpublisher.cpp \
    gpsfollower.cpp \
    main.cpp \
    mainwindow.cpp \
    publisher.cpp \
    subscriber.cpp \
    topic.cpp \

HEADERS += \
    broker.h \
    component.h \
    gpscarpublisher.h \
    gpsfollower.h \
    mainwindow.h \
    publisher.h \
    subscriber.h \
    topic.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
