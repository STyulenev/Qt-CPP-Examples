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

win32 {
    gcc {
        ## Windows common build here
        INCLUDEPATH += "C:\Program Files\MySQL\MySQL Server 8.0\include" # MySQL include folder
        LIBS += "C:\Program Files\MySQL\MySQL Server 8.0\lib\libmysql.dll" # MySQL lib folder
        LIBS += "C:\Program Files\MySQL\MySQL Server 8.0\lib\connection_pool.dll" # MySQL lib folder
    }
}
