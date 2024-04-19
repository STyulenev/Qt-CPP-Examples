INCLUDEPATH += \
        $$PWD/ \
        $$PWD/server/ \
        $$PWD/server/include/ \
        $$PWD/server/handlers/include/

HEADERS += \
        $$files($$PWD/server/include/*.h) \
        $$files($$PWD/server/handlers/include/*.h)

SOURCES += \
        $$files($$PWD/server/*.cpp) \
        $$files($$PWD/server/handlers/*.cpp)

win32-msvc* { # Only MSVC compiler
    ## Windows common build here
    INCLUDEPATH += C:/.../poco-master/Foundation/include
    INCLUDEPATH += C:/.../poco-master/JSON/include
    INCLUDEPATH += C:/.../poco-master/Net/include
    INCLUDEPATH += C:/.../poco-master/XML/include
    INCLUDEPATH += C:/.../poco-master/Util/include

    LIBS += -Wl,-rpath,C:/.../lib -LC:/.../lib # POCO libs folder
    LIBS += -lPocoFoundationd -lPocoNetd -lPocoUtild -lPocoXMLd -lPocoJSONd
}
