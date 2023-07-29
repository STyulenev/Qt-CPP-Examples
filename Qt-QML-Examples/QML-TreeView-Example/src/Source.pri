INCLUDEPATH += \
        $$PWD/model/include/ \
        $$PWD/view-model/include/

HEADERS += \
        $$files($$PWD/model/include/*.h) \
        $$files($$PWD/view-model/include/*.h)

SOURCES += \
        $$files($$PWD/model/*.cpp) \
        $$files($$PWD/view-model/*.cpp)
