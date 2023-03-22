QT += core gui widgets

CONFIG += c++20

TARGET = QTest-Example

OBJECTS_DIR = $$PWD/build/obj # промежуточные объекты
MOC_DIR     = $$PWD/build/moc # промежуточные moc-файлы
DESTDIR     = $$PWD/build/bin # результирующий файл
RCC_DIR     = $$PWD/build/rcc # промежуточные файлы ресурсов
UI_DIR      = $$PWD/build/ui  # промежуточные ui-файлы

include(src/Source.pri)
include(tests/Test.pri)

SOURCES += \
        main.cpp
