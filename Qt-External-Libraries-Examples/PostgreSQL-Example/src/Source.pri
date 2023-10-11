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
    msvc {
        ## Windows common build here
        INCLUDEPATH += "C:\Program Files\PostgreSQL\16\include" # PostgreSQL include folder
        LIBS += "C:\Program Files\PostgreSQL\16\lib\libpq.lib"  # PostgreSQL lib folder
    }

    gcc {
        ## Windows common build here
        INCLUDEPATH += "C:\Program Files\PostgreSQL\16\include" # PostgreSQL include folder
        LIBS += "C:\Program Files\PostgreSQL\16\lib\libpq.dll"  # PostgreSQL lib folder
    }
}
