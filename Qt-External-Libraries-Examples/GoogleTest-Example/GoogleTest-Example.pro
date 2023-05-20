QT -= gui

CONFIG += c++20
CONFIG += console
CONFIG -= app_bundle

TARGET = GoogleTest-Example

OBJECTS_DIR = $$OUT_PWD/obj # промежуточные объекты
MOC_DIR     = $$OUT_PWD/moc # промежуточные moc-файлы
DESTDIR     = $$OUT_PWD/bin # результирующий файл

include(gtest_dependency.pri)

SOURCES += \
        main.cpp \
        src/exampleclass.cpp \
        test_exampleclass.cpp

HEADERS += \
    src/exampleclass.h
