#-------------------------------------------------
#
# Project created by QtCreator 2018-02-15T17:16:07
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UI2
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    learn.cpp

HEADERS  += mainwindow.h \
    learn.h

FORMS    += mainwindow.ui \
    learn.ui
