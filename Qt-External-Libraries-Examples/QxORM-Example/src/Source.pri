QT += sql

DEFINES += _QXORM_EXAMPLE # define for QxORM

PRECOMPILED_HEADER = $$PWD/entity/include/Precompiled.h # QxORM

INCLUDEPATH += \
        $$PWD \
        $$PWD/dao/include/ \
        $$PWD/entity/include/ \
        $$PWD/view-model/include/

HEADERS += \
        $$files($$PWD/dao/include/*.h) \
        $$files($$PWD/entity/include/*.h) \
        $$files($$PWD/view-model/include/*.h)

SOURCES += \
        $$files($$PWD/dao/*.cpp) \
        $$files($$PWD/entity/*.cpp) \
        $$files($$PWD/view-model/*.cpp)

win32 {
    ## Windows common build here
    INCLUDEPATH += C:/.../include/ # QxOrm include folder
    LIBS += -Wl,-rpath,C:/.../lib/ -LC:/.../lib/ # QxOrm lib folder
    LIBS += -lQxOrmd # -lQxOrmd - debug lib, -lQxOrm - release lib
}
