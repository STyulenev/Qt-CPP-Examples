INCLUDEPATH += \
        $$PWD \
        $$PWD/transport/include/

HEADERS += \
        $$files($$PWD/transport/include/*.h)

SOURCES += \
        $$files($$PWD/transport/*.cpp)
