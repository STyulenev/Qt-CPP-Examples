QT -= gui
QT += httpserver

CONFIG += c++20 console
CONFIG -= app_bundle

TARGET = QHttpServer-Example

OBJECTS_DIR = $$PWD/build/obj # промежуточные объекты
MOC_DIR     = $$PWD/build/moc # промежуточные moc-файлы
DESTDIR     = $$PWD/build/bin # результирующий файл
RCC_DIR     = $$PWD/build/rcc # промежуточные файлы ресурсов
UI_DIR      = $$PWD/build/ui  # промежуточные ui-файлы

SOURCES += \
        UserList.cpp \
        main.cpp

HEADERS += \
    UserList.h

