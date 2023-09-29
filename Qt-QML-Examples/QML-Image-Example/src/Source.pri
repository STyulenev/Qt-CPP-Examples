INCLUDEPATH += \
        $$PWD \
        $$PWD/model/include/

HEADERS += \
        $$files($$PWD/model/include/*.h)

SOURCES += \
        $$files($$PWD/model/*.cpp)
