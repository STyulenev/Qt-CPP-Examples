#-------------------------------------------------
#
# Project created by QtCreator 2021-05-17T09:18:29
#
#-------------------------------------------------

CONFIG += plugin
QT += widgets uiplugin

TARGET = $$qtLibraryTarget($$TARGET)
TEMPLATE = lib

SOURCES += \
    MyPlugins.cpp
HEADERS += \
    MyPlugins.h

target.path = $$[QT_INSTALL_PLAGINS]/designer
INSTALLS += target

include(Widgets/Widgets.pri)
include(Plugins/Plugins.pri)

# sudo apt-get install qttools5-dev
# Библиотеку копировать в /usr/lib/x86_64-linux-gnu/qt5/plugins/designer
#sudo cp libPluginCollection.so /usr/lib/x86_64-linux-gnu/qt5/plugins/designer/


