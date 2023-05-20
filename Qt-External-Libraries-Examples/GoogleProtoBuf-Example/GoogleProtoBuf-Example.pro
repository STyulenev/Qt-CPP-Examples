QT += core gui widgets

CONFIG += c++20

TARGET = GoogleProtoBuf-Example

OBJECTS_DIR = $$OUT_PWD/obj # промежуточные объекты
MOC_DIR     = $$OUT_PWD/moc # промежуточные moc-файлы
DESTDIR     = $$OUT_PWD/bin # результирующий файл
UI_DIR      = $$OUT_PWD/ui  # промежуточные ui-файлы

include(src/Source.pri)

SOURCES += \
        main.cpp
