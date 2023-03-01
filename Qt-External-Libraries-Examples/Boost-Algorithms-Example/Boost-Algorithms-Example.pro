QT -= gui

CONFIG += c++20
CONFIG += console
CONFIG -= app_bundle

TARGET = Boost-Algorithms-Example

OBJECTS_DIR = $$OUT_PWD/obj # промежуточные объекты
MOC_DIR     = $$OUT_PWD/moc # промежуточные moc-файлы
DESTDIR     = $$OUT_PWD/bin # результирующий файл
RCC_DIR     = $$OUT_PWD/rcc # промежуточные файлы ресурсов
UI_DIR      = $$OUT_PWD/ui  # промежуточные ui-файлы

HEADERS += \
    SearchingAlgorithms.h

SOURCES += \
        SearchingAlgorithms.cpp \
        main.cpp

win32 {
    ## Windows common build here
    INCLUDEPATH += C:/.../include/ # Boost include path
    LIBS += -Wl,-rpath,C:/.../lib -LC:/.../lib # Boost lib path
    LIBS += $$files($$PWD/*.dll)
}
