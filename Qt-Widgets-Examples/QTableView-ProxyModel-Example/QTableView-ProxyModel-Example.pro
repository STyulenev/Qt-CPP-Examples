QT += core gui widgets

CONFIG += c++20

TARGET = QTableView-ProxyModel-Example

OBJECTS_DIR = $$PWD/build/obj # промежуточные объекты
MOC_DIR     = $$PWD/build/moc # промежуточные moc-файлы
DESTDIR     = $$PWD/build/lib # результирующий файл
RCC_DIR     = $$PWD/build/rcc # промежуточные файлы ресурсов
UI_DIR      = $$PWD/build/ui  # промежуточные ui-файлы

SOURCES += \
    main.cpp \
    MainWindow.cpp \
    proxy-model/ProxyModel.cpp \
    view-model/TableViewModel.cpp

HEADERS += \
    MainWindow.h \
    proxy-model/ProxyModel.h \
    view-model/TableViewModel.h

FORMS += \
    MainWindow.ui
