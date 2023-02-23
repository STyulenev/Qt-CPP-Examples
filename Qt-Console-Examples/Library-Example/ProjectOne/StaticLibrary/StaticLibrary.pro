QT -= gui
QT += core

TARGET = StaticLibrary
CONFIG += c++20 console
CONFIG -= app_bundle
CONFIG += staticlib
TEMPLATE = lib

INCLUDEPATH += $$PWD/include

HEADERS += \
        include/StaticDll.h

SOURCES += \
        StaticDll.cpp
