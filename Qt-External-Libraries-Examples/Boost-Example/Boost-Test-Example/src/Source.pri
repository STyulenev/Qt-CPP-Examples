INCLUDEPATH += \
        $$PWD/logic/include \
        $$PWD/view/include

HEADERS += \
        $$files($$PWD/logic/include/*.h) \
        $$files($$PWD/view/include/*.h)

SOURCES += \
        $$files($$PWD/logic/*.cpp) \
        $$files($$PWD/view/*.cpp)

FORMS += \
        $$files($$PWD/view/ui/*.ui)
