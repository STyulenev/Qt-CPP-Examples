INCLUDEPATH += \
        $$PWD/view/include/ \
        $$PWD/delegate/include/ \
        $$PWD/view-model/include/

HEADERS += \
        $$files($$PWD/view/include/*.h) \
        $$files($$PWD/delegate/include/*.h) \
        $$files($$PWD/view-model/include/*.h)

SOURCES += \
        $$files($$PWD/view/*.cpp) \
        $$files($$PWD/delegate/*.cpp) \
        $$files($$PWD/view-model/*.cpp)

FORMS += \
        $$files($$PWD/view/ui/*.ui)
