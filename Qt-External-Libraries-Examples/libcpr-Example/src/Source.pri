INCLUDEPATH += \
        $$PWD \
        $$PWD/view/include/ \
        $$PWD/network/include/

HEADERS += \
        $$files($$PWD/view/include/*.h) \
        $$files($$PWD/network/include/*.h)

SOURCES += \
        $$files($$PWD/view/*.cpp) \
        $$files($$PWD/network/*.cpp)
		
FORMS += \
        $$files($$PWD/view/ui/*.ui)

win32 { ## Windows common build here
    LIBCPR_DLL     = "C:/3rdparty/libcpr/build/install/bin"     # Path to libcpr.dll
    LIBCPR_INCLUDE = "C:/3rdparty/libcpr/build/install/include" # Path to libcurl headers folder

    exists ($$LIBCPR_INCLUDE) {
        INCLUDEPATH += $$LIBCPR_INCLUDE
        DEPENDPATH  += $$LIBCPR_INCLUDE
    } else {
        message("Error. Don't exists directory - $$LIBCPR_INCLUDE")
    }

    exists ($$LIBCPR_DLL/libcpr.dll) {
        LIBS += -L$$LIBCPR_DLL -lcpr
    } else {
        message("Error. Don't exists library - $$LIBCPR_DLL")
    }
} else::linux {
    message("Error. There are no settings for Linux OS")
} else {
    message("Error. There are no settings for current OS")
}
