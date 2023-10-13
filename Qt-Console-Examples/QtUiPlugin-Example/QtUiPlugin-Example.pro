QT += widgets uiplugin

CONFIG += c++17
CONFIG += plugin
#CONFIG += debug / release

TARGET = $$qtLibraryTarget($$TARGET)
TEMPLATE = lib

CONFIG(debug, debug | release) {
    message("debug mode")

    OBJECTS_DIR = $$OUT_PWD/debug/obj # промежуточные объекты
    MOC_DIR     = $$OUT_PWD/debug/moc # промежуточные moc-файлы
    DESTDIR     = $$OUT_PWD/debug/lib # результирующий файл
    UI_DIR      = $$OUT_PWD/debug/ui  # промежуточные ui-файлы
} else {
    message("release mode")

    OBJECTS_DIR = $$OUT_PWD/release/obj # промежуточные объекты
    MOC_DIR     = $$OUT_PWD/release/moc # промежуточные moc-файлы
    DESTDIR     = $$OUT_PWD/release/lib # результирующий файл
    UI_DIR      = $$OUT_PWD/release/ui  # промежуточные ui-файлы
}

include(Widgets/Widgets.pri)
include(Plugins/Plugins.pri)

SOURCES += \
    MyPlugins.cpp

HEADERS += \
    MyPlugins.h

target.path = $$[QT_INSTALL_PLAGINS]/designer
INSTALLS += target





