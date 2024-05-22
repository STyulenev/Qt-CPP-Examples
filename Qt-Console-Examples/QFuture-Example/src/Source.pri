INCLUDEPATH += \
        $$PWD \
        $$PWD/controller \
        $$PWD/controller/include/

HEADERS += \
        $$files($$PWD/controller/include/*.h)

SOURCES += \
        $$files($$PWD/controller/*.cpp)
