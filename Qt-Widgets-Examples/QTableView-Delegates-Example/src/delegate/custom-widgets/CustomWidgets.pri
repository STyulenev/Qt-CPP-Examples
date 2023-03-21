INCLUDEPATH += \
        $$PWD \
        $$PWD/include/

HEADERS += \
        $$files($$PWD/include/*.h)

SOURCES += \
        $$files($$PWD/*.cpp)

FORMS += \
    $$files($$PWD/ui/*.ui)
