QT += core gui widgets

CONFIG += c++20

TARGET = QTableView-QDataWidgetMapper-Example

OBJECTS_DIR = $$PWD/build/obj # промежуточные объекты
MOC_DIR     = $$PWD/build/moc # промежуточные moc-файлы
DESTDIR     = $$PWD/build/lib # результирующий файл
RCC_DIR     = $$PWD/build/rcc # промежуточные файлы ресурсов
UI_DIR      = $$PWD/build/ui  # промежуточные ui-файлы

include(forms/Forms.pri)
include(view-model/ViewModel.pri)

SOURCES += \
    main.cpp
