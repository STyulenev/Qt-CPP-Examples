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
    CURL_DLL     = "C:/3rdparty/curl-master/build/lib" # Path to libcurl.dll
    CURL_INCLUDE = "C:/3rdparty/curl-master/include"   # Path to libcurl headers folder

    exists ($$CURL_INCLUDE) {
        INCLUDEPATH += $$CURL_INCLUDE
        DEPENDPATH  += $$CURL_INCLUDE
    } else {
        message("Error. Don't exists directory - $$CURL_INCLUDE")
    }

    exists ($$CURL_DLL/libcurl.dll) {
        LIBS += -L$$CURL_DLL -lcurl
    } else {
        message("Error. Don't exists library - $$CURL_DLL")
    }
} else::linux {
    message("Error. There are no settings for Linux OS")
} else {
    message("Error. There are no settings for current OS")
}
