#---------------------------------------------------
#
# Project created by QtCreator 2012-11-19 T 23:46:41
#
#---------------------------------------------------

QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kino-Time-Tracker
TEMPLATE = app

INCLUDEPATH += src \
		src/database

HEADERS += \
    src/MainWindow.h \
    src/EditWindow.h \
    src/database/DatabaseManager.h \
    src/AboutDialog.h \

SOURCES += \
    src/MainWindow.cpp \
    src/Main.cpp \
    src/EditWindow.cpp \
    src/database/DatabaseManager.cpp \
    src/AboutDialog.cpp \

FORMS += \
    ui/MainWindow.ui \
    ui/EditWindow.ui \
    ui/AboutDialog.ui \
