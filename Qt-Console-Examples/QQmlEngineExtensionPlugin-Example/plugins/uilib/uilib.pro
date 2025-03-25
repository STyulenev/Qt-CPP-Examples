TEMPLATE = lib
CONFIG += plugin qmltypes
QT += qml quick

QML_IMPORT_NAME = uilib
QML_IMPORT_MAJOR_VERSION = 1

TARGET = $$qtLibraryTarget(uilibplugin)

HEADERS += \
        MyRectangle.h \
        UILibPlugin.h

SOURCES += \
        MyRectangle.cpp

CONFIG(debug, debug | release) {
    message("debug mode")

    OBJECTS_DIR = $$OUT_PWD/ # промежуточные объекты
    MOC_DIR     = $$OUT_PWD/ # промежуточные moc-файлы
    DESTDIR     = $$OUT_PWD/ # результирующий файл
    RCC_DIR     = $$OUT_PWD/ # промежуточные файлы ресурсов
} else {
    message("release mode")

    OBJECTS_DIR = $$OUT_PWD/ # промежуточные объекты
    MOC_DIR     = $$OUT_PWD/ # промежуточные moc-файлы
    DESTDIR     = $$OUT_PWD/ # результирующий файл
    RCC_DIR     = $$OUT_PWD/ # промежуточные файлы ресурсов
}

DESTPATH=$$OUT_PWD/plugins/$$QML_IMPORT_NAME

target.path=$$DESTPATH
qmldir.files=$$PWD/qmldir
qmldir.path=$$DESTPATH
INSTALLS += target qmldir

OTHER_FILES += \
        qmldir \
        MyTest.qml

# Копирование файлов в plugins/uilib
cpqmldir.files = qmldir MyTest.qml
cpqmldir.path = .
COPIES += cpqmldir
