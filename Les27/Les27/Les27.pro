#-------------------------------------------------
#
# Project created by QtCreator 2016-07-02T12:39:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia multimediawidgets

TARGET = Les27
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    SoundPlayer.cpp \
    VideoPlayer.cpp

HEADERS  += mainwindow.h \
    SoundPlayer.h \
    VideoPlayer.h

FORMS    += mainwindow.ui

RESOURCES +=
