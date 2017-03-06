#-------------------------------------------------
#
# Project created by QtCreator 2016-07-12T09:45:03
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = ../TestLib
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    test.cpp \
    MyClass.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    MyClass.h
