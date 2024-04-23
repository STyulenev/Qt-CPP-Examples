INCLUDEPATH += \
        $$PWD/ \
        $$PWD/model/ \
        $$PWD/model/include/ \
        $$PWD/server/ \
        $$PWD/server/include/ \
        $$PWD/server/handlers/include/

HEADERS += \
        $$files($$PWD/model/include/*.h) \
        $$files($$PWD/server/include/*.h) \
        $$files($$PWD/server/handlers/include/*.h)

SOURCES += \
        $$files($$PWD/model/*.cpp) \
        $$files($$PWD/server/*.cpp) \
        $$files($$PWD/server/handlers/*.cpp)

win32 {
    ## Windows common build here

    gcc {
        INCLUDEPATH += C:/3rdparty/poco-install/include # Poco include folder

        LIBS += -Wl,-rpath,C:/3rdparty/poco-install/bin -LC:/3rdparty/poco-install/bin # POCO libs folder
        LIBS += -lPocoFoundation -lPocoNet -lPocoUtil -lPocoXML -lPocoJSON
    } else::clang {
        message("Error")
    } else::mcvs {
        message("Error")
    } else {
        message("Error")
    }

} else::linux {
    message("Error. There are no settings for Linux OS")
} else {
    message("Error. There are no settings for current OS")
}
