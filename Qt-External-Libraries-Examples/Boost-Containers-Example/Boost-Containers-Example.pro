QT -= gui

CONFIG += c++20
CONFIG += console
CONFIG -= app_bundle

TARGET = Boost-Containers-Example

OBJECTS_DIR = $$OUT_PWD/obj # промежуточные объекты
MOC_DIR     = $$OUT_PWD/moc # промежуточные moc-файлы
DESTDIR     = $$OUT_PWD/bin # результирующий файл

include(containers-examples/Source.pri)

SOURCES += \
        main.cpp
