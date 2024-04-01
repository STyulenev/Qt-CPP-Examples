INCLUDEPATH += \
        $$PWD/controller/include/ \
        $$PWD/view/include/ \
        $$PWD/widget/include/

HEADERS += \
        $$files($$PWD/controller/include/*.h) \
        $$files($$PWD/view/include/*.h) \
        $$files($$PWD/widget/include/*.h)

SOURCES += \
        $$files($$PWD/controller/*.cpp) \
        $$files($$PWD/view/*.cpp) \
        $$files($$PWD/widget/*.cpp)

FORMS += \
        $$files($$PWD/view/ui/*.ui)
