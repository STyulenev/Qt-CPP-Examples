INCLUDEPATH += \
        $$PWD/screen/include/ \
        $$PWD/view/include/

HEADERS += \
        $$files($$PWD/screen/include/*.h) \
        $$files($$PWD/view/include/*.h)

SOURCES += \
        $$files($$PWD/screen/*.cpp) \
        $$files($$PWD/view/*.cpp)

FORMS += \
        $$files($$PWD/screen/ui/*.ui) \
        $$files($$PWD/view/ui/*.ui)
