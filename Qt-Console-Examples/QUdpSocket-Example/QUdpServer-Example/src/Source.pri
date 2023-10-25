INCLUDEPATH += \
        $$PWD \
        $$PWD/core/include/ \
        $$PWD/transport/include/

HEADERS += \
        $$files($$PWD/core/include/*.h) \
        $$files($$PWD/transport/include/*.h)

SOURCES += \
        $$files($$PWD/core/*.cpp) \
        $$files($$PWD/transport/*.cpp)
