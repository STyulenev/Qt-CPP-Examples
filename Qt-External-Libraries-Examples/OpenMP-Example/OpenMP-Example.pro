QT -= gui
QT += core testlib

CONFIG += c++20

TEMPLATE = app
TARGET = OpenMP-Example

OBJECTS_DIR = $$OUT_PWD/obj # промежуточные объекты
MOC_DIR     = $$OUT_PWD/moc # промежуточные moc-файлы
DESTDIR     = $$OUT_PWD/bin # результирующий файл

QMAKE_LIBS+=-static -lgomp -lpthread
QMAKE_CXXFLAGS+=-msse3 -fopenmp

SOURCES += \
    functions.cpp \
    main.cpp \
    test.cpp

HEADERS += \
    functions.h \
    test.h
