QT += qml quick

CONFIG += c++20
#CONFIG += debug / release

TARGET = QML-QQmlEngineExtensionPlugin-Example
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG(debug, debug | release) {
    message("debug mode")

    OBJECTS_DIR = $$OUT_PWD/debug/obj # промежуточные объекты
    MOC_DIR     = $$OUT_PWD/debug/moc # промежуточные moc-файлы
    DESTDIR     = $$OUT_PWD/bin       # результирующий файл
    RCC_DIR     = $$OUT_PWD/debug/rcc # промежуточные файлы ресурсов
} else {
    message("release mode")

    OBJECTS_DIR = $$OUT_PWD/release/obj # промежуточные объекты
    MOC_DIR     = $$OUT_PWD/release/moc # промежуточные moc-файлы
    DESTDIR     = $$OUT_PWD/bin         # результирующий файл
    RCC_DIR     = $$OUT_PWD/release/rcc # промежуточные файлы ресурсов
}

win32: DESTDIR = ./

QML_IMPORT_PATH += $$OUT_PWD/plugins

SOURCES += \
        main.cpp

RESOURCES += \
        resource.qrc

#target.path = $$OUT_PWD/...
INSTALLS += target
