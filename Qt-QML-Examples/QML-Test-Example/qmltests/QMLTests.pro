CONFIG += warn_on qmltestcase
CONFIG += c++20
#CONFIG += debug / release

TEMPLATE = app
TARGET = QMLTests

DISTFILES += \
        $$files($$PWD/view-model/tst_*.qml)

SOURCES += \
        main.cpp
