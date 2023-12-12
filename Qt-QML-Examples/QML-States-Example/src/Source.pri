INCLUDEPATH += \
        $$PWD \
        $$PWD/view-model/include/

HEADERS += \
        $$files($$PWD/view-model/include/*.h)

SOURCES += \
        $$files($$PWD/view-model/*.cpp)
