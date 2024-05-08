INCLUDEPATH += \
        $$PWD

SOURCES += \
        $$files($$PWD/*.cpp)

win32 { ## Windows common build here
    INCLUDEPATH += C:/3rdparty/cpputest-master/include # CppUTest include folder
    LIBS += -Wl,-rpath,C:/3rdparty/cpputest-master/build/src/CppUTest -LC:/3rdparty/cpputest-master/build/src/CppUTest # CppUTest lib folder
    LIBS += -lCppUTest# libCppUTest.a
} else::linux {
    message("Error. There are no settings for Linux OS")
} else {
    message("Error. There are no settings for current OS")
}
