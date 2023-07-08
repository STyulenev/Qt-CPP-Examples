QT -= gui

CONFIG += c++20
CONFIG += console
CONFIG -= app_bundle
#CONFIG += debug / release

TEMPLATE = app
TARGET = GoogleTest-Example

CONFIG(debug, debug | release) {
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

include(gtest_dependency.pri)

SOURCES += \
        main.cpp \
        src/exampleclass.cpp \
        test_exampleclass.cpp

HEADERS += \
    src/exampleclass.h
