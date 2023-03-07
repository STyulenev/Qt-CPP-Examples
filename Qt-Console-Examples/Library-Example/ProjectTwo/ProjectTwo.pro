QT -= gui

CONFIG += c++20 console
CONFIG -= app_bundle

TEMPLATE = app
TARGET = ProjectTwo

SOURCES += \
        main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SharedLibrary/release/ -lSharedLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SharedLibrary/debug/ -lSharedLibrary
else:unix: LIBS += -L$$OUT_PWD/../SharedLibrary/ -lSharedLibrary

INCLUDEPATH += $$PWD/../SharedLibrary/include
DEPENDPATH += $$PWD/../SharedLibrary/include
