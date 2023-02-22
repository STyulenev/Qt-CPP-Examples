QT += core gui widgets

CONFIG += c++20

TARGET = QComboBox-Delegate-Example

OBJECTS_DIR = $$PWD/build/obj # промежуточные объекты
MOC_DIR     = $$PWD/build/moc # промежуточные moc-файлы
DESTDIR     = $$PWD/build/lib # результирующий файл
RCC_DIR     = $$PWD/build/rcc # промежуточные файлы ресурсов
UI_DIR      = $$PWD/build/ui  # промежуточные ui-файлы

SOURCES += \
    QComboBoxDelegate.cpp \
    QComboBoxModel.cpp \
    TableViewModel.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h \
    QComboBoxDelegate.h \
    QComboBoxModel.h \
    TableViewModel.h \
    TestModel.h

FORMS += \
    MainWindow.ui

RESOURCES += \
    resource.qrc
