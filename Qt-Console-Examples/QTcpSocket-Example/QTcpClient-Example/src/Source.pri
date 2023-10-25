INCLUDEPATH += \
        $$PWD \
        $$PWD/core/include/ \
        $$PWD/transport/include/ \
        $$PWD/view/include/

HEADERS += \
        $$files($$PWD/core/include/*.h) \
        $$files($$PWD/transport/include/*.h) \
        $$files($$PWD/view/include/*.h)

SOURCES += \
        $$files($$PWD/core/*.cpp) \
        $$files($$PWD/transport/*.cpp) \
        $$files($$PWD/view/*.cpp)

FORMS += \
        $$files($$PWD/view/ui/*.ui)
