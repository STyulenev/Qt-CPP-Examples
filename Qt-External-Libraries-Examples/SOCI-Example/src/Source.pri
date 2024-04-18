INCLUDEPATH += \
        $$PWD \
        $$PWD/dao/include/ \
        $$PWD/entity/include/ \
        $$PWD/view/include/ \
        $$PWD/view-model/include/

HEADERS += \
        $$files($$PWD/dao/include/*.h) \
        $$files($$PWD/entity/include/*.h) \
        $$files($$PWD/view/include/*.h) \
        $$files($$PWD/view-model/include/*.h)

SOURCES += \
        $$files($$PWD/dao/*.cpp) \
        $$files($$PWD/entity/*.cpp) \
        $$files($$PWD/view/*.cpp) \
        $$files($$PWD/view-model/*.cpp)
		
FORMS += \
        $$files($$PWD/view/ui/*.ui)

win32 { ## Windows common build here

    INCLUDEPATH += C:/PostgreSQL/16/include # PostgreSQL include folder
    LIBS += C:/PostgreSQL/16/lib/libpq.dll  # PostgreSQL lib folder

    INCLUDEPATH += C:/3rdparty/soci-master/build/include # PSOCI include folder
    INCLUDEPATH += C:/3rdparty/soci-master/include       # SOCI include folder
    LIBS += -Wl,-rpath,C:/3rdparty/soci-master/build/bin/ -LC:/3rdparty/soci-master/build/bin/ # SOCI libs folder
    LIBS += -lsoci_core_4_1 -lsoci_empty_4_1 -lsoci_odbc_4_1 -lsoci_postgresql_4_1

} else::linux {
    message("Error. There are no settings for Linux OS")
} else {
    message("Error. There are no settings for current OS")
}
