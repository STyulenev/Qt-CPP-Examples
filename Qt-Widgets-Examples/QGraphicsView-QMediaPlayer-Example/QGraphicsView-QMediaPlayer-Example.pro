QT += core gui widgets

CONFIG += c++20
#CONFIG += debug / release

TARGET = QGraphicsView-QMediaPlayer-Example

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

include(src/Source.pri)

SOURCES += \
        main.cpp
