QT += quick

CONFIG += c++17

TARGET = QML-ChartView-Example
TEMPLATE = app

CONFIG(debug, debug | release) {
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

SOURCES += \
        main.cpp

RESOURCES += \
        resource.qrc