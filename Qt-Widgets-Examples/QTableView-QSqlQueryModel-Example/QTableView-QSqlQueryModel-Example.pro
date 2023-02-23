QT += core gui widgets sql

CONFIG += c++20

TARGET = QTableView-QSqlQueryModel-Example

OBJECTS_DIR = $$PWD/build/obj # промежуточные объекты
MOC_DIR     = $$PWD/build/moc # промежуточные moc-файлы
DESTDIR     = $$PWD/build/lib # результирующий файл
RCC_DIR     = $$PWD/build/rcc # промежуточные файлы ресурсов
UI_DIR      = $$PWD/build/ui  # промежуточные ui-файлы

SOURCES += \
    main.cpp \
    MainWindow.cpp \
    view-model/TableModel.cpp

HEADERS += \
    MainWindow.h \
    view-model/TableModel.h

FORMS += \
    MainWindow.ui
