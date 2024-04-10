QT -= gui
QT += core

CONFIG += c++20 console
CONFIG -= app_bundle
#CONFIG += debug / release

TARGET = QHttpServer-Example
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG(debug, release) { # debug|release
    message("debug mode")

    OBJECTS_DIR = $$OUT_PWD/debug/obj # промежуточные объекты
    MOC_DIR     = $$OUT_PWD/debug/moc # промежуточные moc-файлы
    DESTDIR     = $$OUT_PWD/debug/bin # результирующий файл
} else {
    message("release mode")

    OBJECTS_DIR = $$OUT_PWD/release/obj # промежуточные объекты
    MOC_DIR     = $$OUT_PWD/release/moc # промежуточные moc-файлы
    DESTDIR     = $$OUT_PWD/release/bin # результирующий файл
}

include(src/Source.pri)

SOURCES += \
        main.cpp
