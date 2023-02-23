QT -= gui

CONFIG += c++20 console
CONFIG -= app_bundle

TEMPLATE = app
TARGET = ProjectOne

SOURCES += \
        main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SharedLibrary/release/ -lSharedLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SharedLibrary/debug/ -lSharedLibrary
else:unix: LIBS += -L$$OUT_PWD/../SharedLibrary/ -lSharedLibrary

INCLUDEPATH += $$PWD/../SharedLibrary/include
DEPENDPATH += $$PWD/../SharedLibrary/include

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/ProjectOne/StaticLibrary/release/ -lStaticLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/ProjectOne/StaticLibrary/debug/ -lStaticLibrary
else:unix: LIBS += -L$$OUT_PWD/ProjectOne/StaticLibrary/ -lStaticLibrary

INCLUDEPATH += $$PWD/StaticLibrary/include
DEPENDPATH += $$PWD/StaticLibrary/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/ProjectOne/StaticLibrary/release/libStaticLibrary.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/ProjectOne/StaticLibrary/debug/libStaticLibrary.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/ProjectOne/StaticLibrary/release/StaticLibrary.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/ProjectOne/StaticLibrary/debug/StaticLibrary.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/ProjectOne/StaticLibrary/libStaticLibrary.a
