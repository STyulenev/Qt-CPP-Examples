
INCLUDEPATH += \
        $$PWD \
        $$PWD/include/

HEADERS += \
        $$files($$PWD/include/*.h)

SOURCES += \
        $$files($$PWD/*.cpp)
		
win32 {
    ## Windows common build here
    INCLUDEPATH += C:/.../include/ # Boost include path
    LIBS += -Wl,-rpath,C:/.../lib -LC:/.../lib # Boost lib path
    LIBS += $$files($$PWD/*.dll)
}
