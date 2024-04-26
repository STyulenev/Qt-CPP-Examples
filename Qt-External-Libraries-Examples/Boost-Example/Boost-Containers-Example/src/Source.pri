INCLUDEPATH += \
        $$PWD \
        $$PWD/include/

HEADERS += \
        $$files($$PWD/include/*.h)

SOURCES += \
        $$files($$PWD/*.cpp)
		
win32 {
    ## Windows common build here

    mingw {
        INCLUDEPATH += C:/3rdparty/boost_1_85_0/boost-install/include/boost-1_85/ # Boost include path
        LIBS += -Wl,-rpath,C:/3rdparty/boost_1_85_0/boost-install/lib -LC:/3rdparty/boost_1_85_0/boost-install/lib # Boost lib path
        LIBS += $$files($$PWD/*.dll)

        message("OK. There is boost library for MinGW compiler on the current OS")
    } else {
        message("Error. There is no boost library for this compiler on the current OS")
    }

} else::linux {
    message("Error. There are no settings for Linux OS")
} else {
    message("Error. There are no settings for current OS")
}
