QT += core gui widgets

CONFIG += c++20

TARGET = QSettings-Example

OBJECTS_DIR = $$PWD/build/obj # промежуточные объекты
MOC_DIR     = $$PWD/build/moc # промежуточные moc-файлы
DESTDIR     = $$PWD/build/lib # результирующий файл
RCC_DIR     = $$PWD/build/rcc # промежуточные файлы ресурсов
UI_DIR      = $$PWD/build/ui  # промежуточные ui-файлы

SOURCES += \
    Setting.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    Setting.h \
    MainWindow.h \

FORMS += \
    MainWindow.ui
