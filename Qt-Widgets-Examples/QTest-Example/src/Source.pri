INCLUDEPATH += \
        $$PWD/view/include

HEADERS += \
        $$files($$PWD/view/include/*.h)

SOURCES += \
        $$files($$PWD/view/*.cpp)

FORMS += \
        $$files($$PWD/view/ui/*.ui)
