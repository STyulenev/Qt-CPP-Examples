QT += core
QT -= gui

TARGET = TestPlugin
TEMPLATE = lib
CONFIG += plugin

SOURCES += \
    ConcretePlugin.cpp

HEADERS += \
        ../include/IPlugin.h \
        ConcretePlugin.h

INCLUDEPATH += \
        ../include/

RESOURCES += \
        resource.qrc
