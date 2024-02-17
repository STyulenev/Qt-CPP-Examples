INCLUDEPATH += \
        $$PWD \
        $$PWD/xml/include/

HEADERS += \
        $$files($$PWD/xml/include/*.h)

SOURCES += \
        $$files($$PWD/xml/*.cpp)
