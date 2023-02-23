QT += core gui widgets

CONFIG += c++20

TARGET = QTableView-Delegates-Example

OBJECTS_DIR = $$PWD/build/obj # промежуточные объекты
MOC_DIR     = $$PWD/build/moc # промежуточные moc-файлы
DESTDIR     = $$PWD/build/lib # результирующий файл
RCC_DIR     = $$PWD/build/rcc # промежуточные файлы ресурсов
UI_DIR      = $$PWD/build/ui  # промежуточные ui-файлы

include(custom-delegates/SustomDelegates.pri)
include(custom-widgets/CustomWidgets.pri)
include(simple-delegates/SimpleDelegates.pri)
include(styled-delegates/StyledDelegates.pri)
include(view-model/ViewModel.pri)

SOURCES += \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h 

FORMS += \
    MainWindow.ui

RESOURCES += \
    res.qrc
