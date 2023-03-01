QT += core gui widgets

CONFIG += c++20

TEMPLATE = app
TARGET = QXlsx-Example

OBJECTS_DIR = $$OUT_PWD/obj # промежуточные объекты
MOC_DIR     = $$OUT_PWD/moc # промежуточные moc-файлы
DESTDIR     = $$OUT_PWD/lib # результирующий файл
RCC_DIR     = $$OUT_PWD/rcc # промежуточные файлы ресурсов
UI_DIR      = $$OUT_PWD/ui  # промежуточные ui-файлы

SOURCES += \
    TableViewModel.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h  \
    TableViewModel.h

FORMS += \
    MainWindow.ui

win32 {
    ## Windows common build here
    INCLUDEPATH += C:/.../QXlsx/header/ # Path to QXlsx headers folder
	DEPENDPATH += C:/.../QXlsx/header/

	LIBS += -LC:/.../lib/ -lQXlsxQt6 # Path to libQXlsxQt6.dll
}