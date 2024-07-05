INCLUDEPATH += \
        $$PWD/controller/include/ \
        $$PWD/view/include/

HEADERS += \
        $$files($$PWD/controller/include/*.h) \
        $$files($$PWD/view/include/*.h)

SOURCES += \
        $$files($$PWD/controller/*.cpp) \
        $$files($$PWD/view/*.cpp)

FORMS += \
        $$files($$PWD/view/ui/*.ui)
