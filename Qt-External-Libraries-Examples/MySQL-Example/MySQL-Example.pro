QT += core gui widgets

CONFIG += c++20

TARGET = MySQL-Example

OBJECTS_DIR = $$OUT_PWD/build/obj # промежуточные объекты
MOC_DIR     = $$OUT_PWD/build/moc # промежуточные moc-файлы
DESTDIR     = $$OUT_PWD/build/bin # результирующий файл
RCC_DIR     = $$OUT_PWD/build/rcc # промежуточные файлы ресурсов
UI_DIR      = $$OUT_PWD/build/ui  # промежуточные ui-файлы

include(src/Source.pri)

SOURCES += \
        main.cpp
