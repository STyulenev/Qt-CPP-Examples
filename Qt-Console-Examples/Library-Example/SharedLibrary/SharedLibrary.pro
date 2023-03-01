QT -= gui
QT += core

TARGET = SharedLibrary
CONFIG += c++20 console
CONFIG -= app_bundle
TEMPLATE = lib

DEFINES += SHARED_LIBRARY

INCLUDEPATH += $$PWD/include

HEADERS += \
        include/SharedDllGlobal.h \
        include/SharedDll.h

SOURCES += \
        SharedDll.cpp
