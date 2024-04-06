INCLUDEPATH += \
        $$PWD

SOURCES += \
        $$files($$PWD/*.cpp)

win32 { ## Windows common build here
    INCLUDEPATH += C:/3rdparty/Celero-master/build/install/include # Celero include folder
    LIBS += -Wl,-rpath,C:/3rdparty/Celero-master/build/install/lib -LC:/3rdparty/Celero-master/build/install/lib # Celero lib folder
    LIBS += -lcelero # libcelero.dll
} else::linux {
    message("Error. There are no settings for Linux OS")
} else {
    message("Error. There are no settings for current OS")
}
