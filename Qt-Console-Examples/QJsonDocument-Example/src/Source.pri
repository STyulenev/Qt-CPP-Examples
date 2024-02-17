INCLUDEPATH += \
        $$PWD \
        $$PWD/json/include/

HEADERS += \
        $$files($$PWD/json/include/*.h)

SOURCES += \
        $$files($$PWD/json/*.cpp)
