INCLUDEPATH += \
        $$PWD/setting/include \
        $$PWD/view/include

HEADERS += \
        $$files($$PWD/setting/include/*.h) \
        $$files($$PWD/view/include/*.h)

SOURCES += \
        $$files($$PWD/setting/*.cpp) \
        $$files($$PWD/view/*.cpp)

FORMS += \
        $$files($$PWD/view/ui/*.ui)
