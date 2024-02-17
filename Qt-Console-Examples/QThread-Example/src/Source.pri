INCLUDEPATH += \
        $$PWD \
        $$PWD/some-controller/include/

HEADERS += \
        $$files($$PWD/some-controller/include/*.h)

SOURCES += \
        $$files($$PWD/some-controller/*.cpp)
