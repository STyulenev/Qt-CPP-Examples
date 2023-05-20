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

win32 {
    ## Windows common build here
    INCLUDEPATH += C:/3rdparty/curl-master/include # Path to libcurl headers folder
    DEPENDPATH += C:/3rdparty/curl-master/include

    LIBS += -LC:/3rdparty/curl-master/build/lib/ -lcurl # Path to libcurl.dll
}
