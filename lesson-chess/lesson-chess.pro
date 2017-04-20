QT += core
QT -= gui

CONFIG += c++11

TARGET = lesson-chess
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    output.cpp

HEADERS += \
    output.h \
    common.h
