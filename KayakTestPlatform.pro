#-------------------------------------------------
#
# Project created by QtCreator 2013-01-13T02:16:53
#
#-------------------------------------------------

QT       += core
QT       -= gui

TARGET = KayakTestPlatform
CONFIG   += console
CONFIG   -= app_bundle

QMAKE_CFLAGS   += -fms-extensions -Wall
QMAKE_CXXFLAGS += -fms-extensions

TEMPLATE = app


SOURCES += main.cpp \
    kayakapp.cpp \
    cmdqueue.c

HEADERS += \
    kayakapp.h \
    cmdqueue.h
