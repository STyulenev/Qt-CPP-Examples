QT += core gui widgets

CONFIG += c++20

TARGET = QListWidget-Example

OBJECTS_DIR = $$PWD/build/obj # промежуточные объекты
MOC_DIR     = $$PWD/build/moc # промежуточные moc-файлы
DESTDIR     = $$PWD/build/lib # результирующий файл
RCC_DIR     = $$PWD/build/rcc # промежуточные файлы ресурсов
UI_DIR      = $$PWD/build/ui  # промежуточные ui-файлы

SOURCES += \
    CustomWidget.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    CustomWidget.h \
    MainWindow.h \

FORMS += \
    CustomWidget.ui \
    MainWindow.ui

RESOURCES += \
    res.qrc
