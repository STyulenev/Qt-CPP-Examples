QT += core
QT += gui
QT += widgets

CONFIG += c++20 console
CONFIG -= app_bundle

TARGET = LimonReport-Example

OBJECTS_DIR = $$OUT_PWD/obj # промежуточные объекты
MOC_DIR     = $$OUT_PWD/moc # промежуточные moc-файлы
DESTDIR     = $$OUT_PWD/bin # результирующий файл
RCC_DIR     = $$OUT_PWD/rcc # промежуточные файлы ресурсов
UI_DIR      = $$OUT_PWD/ui  # промежуточные ui-файлы

include(tools/lime-report.pri)
include(view-model/ViewModel.pri)

SOURCES += \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h

FORMS += \
    MainWindow.ui

RESOURCES += \
    resources/res.qrc
