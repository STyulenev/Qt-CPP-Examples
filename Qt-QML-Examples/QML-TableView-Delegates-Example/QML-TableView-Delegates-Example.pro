QT += quick

CONFIG += c++20
CONFIG += debug # release

TARGET = QML-TableView-Delegates-Example

CONFIG(debug, release) { # debug|release
    message("debug mode")

    OBJECTS_DIR = $$OUT_PWD/debug/obj # промежуточные объекты
    MOC_DIR     = $$OUT_PWD/debug/moc # промежуточные moc-файлы
    DESTDIR     = $$OUT_PWD/debug/bin # результирующий файл
    RCC_DIR     = $$OUT_PWD/debug/rcc # промежуточные файлы ресурсов
} else {
    message("release mode")

    OBJECTS_DIR = $$OUT_PWD/release/obj # промежуточные объекты
    MOC_DIR     = $$OUT_PWD/release/moc # промежуточные moc-файлы
    DESTDIR     = $$OUT_PWD/release/bin # результирующий файл
    RCC_DIR     = $$OUT_PWD/release/rcc # промежуточные файлы ресурсов
}

QML_IMPORT_PATH += $$PWD/qml

INCLUDEPATH += src/

HEADERS += \
        src/TableModel.h

SOURCES += \
        src/TableModel.cpp \
        main.cpp

RESOURCES += \
        resource.qrc
