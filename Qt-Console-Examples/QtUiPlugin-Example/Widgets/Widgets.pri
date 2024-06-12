INCLUDEPATH += $$PWD/

SOURCES += \
        $$PWD/ToleranceBar.cpp

HEADERS += \
        $$PWD/ToleranceBar.h

QtUiPlugin.path = "/usr/include/x86_64-linux-gnu/qt5/QtUiPlugin"
QtUiPlugin.files = $$PWD/ToleranceBar.h
INSTALLS += QtUiPlugin
