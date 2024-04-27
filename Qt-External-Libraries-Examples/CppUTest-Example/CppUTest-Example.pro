QT += core widgets

CONFIG += c++20
#CONFIG += debug / release
CONFIG += testConfig #applicationConfig

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG(debug, debug | release) {
    message("debug mode")

    OBJECTS_DIR = $$OUT_PWD/debug/obj # промежуточные объекты
    MOC_DIR     = $$OUT_PWD/debug/moc # промежуточные moc-файлы
    DESTDIR     = $$OUT_PWD/debug/bin # результирующий файл
    UI_DIR      = $$OUT_PWD/debug/ui  # промежуточные ui-файлы
} else {
    message("release mode")

    OBJECTS_DIR = $$OUT_PWD/release/obj # промежуточные объекты
    MOC_DIR     = $$OUT_PWD/release/moc # промежуточные moc-файлы
    DESTDIR     = $$OUT_PWD/release/bin # результирующий файл
    UI_DIR      = $$OUT_PWD/release/ui  # промежуточные ui-файлы
}

applicationConfig {
    TARGET = CppUTest-Example
    TEMPLATE = app

    include(src/Source.pri)

    SOURCES += \
        main.cpp
}

testConfig {
    TARGET = Test-bin
    TEMPLATE = app

    include(src/Source.pri)
    include(tests/Tests.pri)
}
