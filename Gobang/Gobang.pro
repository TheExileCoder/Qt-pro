#-------------------------------------------------
#
# Project created by QtCreator 2020-07-06T17:35:48
#
#-------------------------------------------------

QT       += core gui

QT      += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gobang
TEMPLATE = app


SOURCES += main.cpp \
        widget.cpp \
    gamewindow.cpp \
    mychess.cpp \
    win.cpp

HEADERS  += widget.h \
    gamewindow.h \
    mychess.h \
    win.h

FORMS    += widget.ui \
    gamewindow.ui

RESOURCES += \
    myresource.qrc

DISTFILES += \
    Gamewindow.qml \
    GamewindowForm.ui.qml

