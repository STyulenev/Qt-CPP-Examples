QT += core
QT -= gui

CONFIG += c++11

TARGET = QLibrary-Example
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += \
        LibraryController.h

SOURCES += \
        main.cpp \
        LibraryController.cpp
