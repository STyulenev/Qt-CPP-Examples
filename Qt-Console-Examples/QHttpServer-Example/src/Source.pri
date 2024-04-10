QT += httpserver concurrent

INCLUDEPATH += \
        $$PWD \
        $$PWD/core/include/ \
        $$PWD/model/include/ \
        $$PWD/transport/include/

HEADERS += \
        $$files($$PWD/core/include/*.h) \
        $$files($$PWD/model/include/*.h) \
        $$files($$PWD/transport/include/*.h)

SOURCES += \
        $$files($$PWD/core/*.cpp) \
        $$files($$PWD/model/*.cpp) \
        $$files($$PWD/transport/*.cpp)
