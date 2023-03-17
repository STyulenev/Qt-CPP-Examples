INCLUDEPATH += \
        $$PWD/view-model/delegate/ \
        $$PWD/view-model/model/ \
        $$PWD/view-model/include/ \
        $$PWD/view/include/

HEADERS += \
        $$files($$PWD/view/include/*.h) \
        $$files($$PWD/view-model/include/*.h) \
        $$files($$PWD/view-model/model/*.h) \
        $$files($$PWD/view-model/delegate/*.h)

SOURCES += \
        $$files($$PWD/view/*.cpp) \
        $$files($$PWD/view-model/delegate/*.cpp) \
        $$files($$PWD/view-model/*.cpp)

FORMS += \
        $$files($$PWD/view/ui/*.ui)

