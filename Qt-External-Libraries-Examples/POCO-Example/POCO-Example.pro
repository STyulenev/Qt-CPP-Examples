QT -= gui

CONFIG += c++20 console
CONFIG -= app_bundle

TARGET = POCO-Example

OBJECTS_DIR = $$OUT_PWD/obj # промежуточные объекты
MOC_DIR     = $$OUT_PWD/moc # промежуточные moc-файлы
DESTDIR     = $$OUT_PWD/bin # результирующий файл

include(src/Source.pri)

SOURCES += \
        main.cpp
