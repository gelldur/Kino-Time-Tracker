#-------------------------------------------------
#
# Project created by QtCreator 2012-11-19T23:46:41
#
#-------------------------------------------------

QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kino-Time-Tracker
TEMPLATE = app

OTHER_FILES +=

INCLUDEPATH += src \
		src/database

HEADERS += \
    src/mainwindow.h \
    src/editwindow.h \
    src/database/DatabaseManager.h

SOURCES += \
    src/mainwindow.cpp \
    src/main.cpp \
    src/editwindow.cpp \
    src/database/DatabaseManager.cpp

FORMS += \
    ui/mainwindow.ui \
    ui/editwindow.ui

RESOURCES += \
    resources.qrc
