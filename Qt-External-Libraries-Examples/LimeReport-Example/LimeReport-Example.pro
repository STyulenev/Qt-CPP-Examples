QT += core
QT += gui
QT += widgets

CONFIG += c++20 console
CONFIG -= app_bundle

TARGET = LimeReport-Example

OBJECTS_DIR = $$OUT_PWD/obj # промежуточные объекты
MOC_DIR     = $$OUT_PWD/moc # промежуточные moc-файлы
DESTDIR     = $$OUT_PWD/bin # результирующий файл
RCC_DIR     = $$OUT_PWD/rcc # промежуточные файлы ресурсов
UI_DIR      = $$OUT_PWD/ui  # промежуточные ui-файлы

include(tools/lime-report.pri)
include(src/Source.pri)

SOURCES += \
        main.cpp

RESOURCES += \
        resource.qrc
