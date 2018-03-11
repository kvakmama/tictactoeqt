TEMPLATE = app
TARGET = juciqt

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
SOURCES += main.cpp \
    window.cpp \
    button.cpp

HEADERS += \
    window.h \
    button.h
