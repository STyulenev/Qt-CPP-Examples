QT += core gui widgets

CONFIG += c++20

TARGET = QxORM-Example

OBJECTS_DIR = $$OUT_PWD/build/obj # промежуточные объекты
MOC_DIR     = $$OUT_PWD/build/moc # промежуточные moc-файлы
DESTDIR     = $$OUT_PWD/build/bin # результирующий файл
UI_DIR      = $$OUT_PWD/build/ui  # промежуточные ui-файлы

include(src/Source.pri)

SOURCES += \
        main.cpp
