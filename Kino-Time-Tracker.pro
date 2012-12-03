#-------------------------------------------------
#
# Project created by QtCreator 2012-11-19T23:46:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kino-Time-Tracker
TEMPLATE = app

OTHER_FILES += \
    resources/list.txt

HEADERS += \
    src/mainwindow.h \
    src/editwindow.h

SOURCES += \
    src/mainwindow.cpp \
    src/main.cpp \
    src/editwindow.cpp

FORMS += \
    ui/mainwindow.ui \
    ui/editwindow.ui
