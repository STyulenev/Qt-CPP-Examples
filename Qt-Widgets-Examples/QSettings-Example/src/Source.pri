INCLUDEPATH += \
        $$PWD/view/include/ \
        $$PWD/setting/include/

HEADERS += \
        $$files($$PWD/view/include/*.h) \
        $$files($$PWD/setting/include/*.h)

SOURCES += \
        $$files($$PWD/view/*.cpp) \
        $$files($$PWD/setting/*.cpp)

FORMS += \
        $$files($$PWD/view/ui/*.ui)
