QT += core gui widgets

CONFIG += c++20

TARGET = GoogleProtoBuf-Example

OBJECTS_DIR = $$OUT_PWD/obj # промежуточные объекты
MOC_DIR     = $$OUT_PWD/moc # промежуточные moc-файлы
DESTDIR     = $$OUT_PWD/lib # результирующий файл
RCC_DIR     = $$OUT_PWD/rcc # промежуточные файлы ресурсов
UI_DIR      = $$OUT_PWD/ui  # промежуточные ui-файлы

include(protobuf/Protobuf.pri)

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h 

FORMS += \
    mainwindow.ui