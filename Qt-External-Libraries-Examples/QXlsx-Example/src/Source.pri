INCLUDEPATH += \
        $$PWD \
        $$PWD/view/include/ \
        $$PWD/view-model/include/

HEADERS += \
        $$files($$PWD/view/include/*.h) \
        $$files($$PWD/view-model/include/*.h)

SOURCES += \
        $$files($$PWD/view/*.cpp) \
        $$files($$PWD/view-model/*.cpp)
		
FORMS += \
        $$files($$PWD/view/ui/*.ui)

win32 {
    ## Windows common build here
    INCLUDEPATH += C:/3rdparty/QXlsx-master/QXlsx/header/ # Path to QXlsx headers folder
    DEPENDPATH += C:/3rdparty/QXlsx-master/QXlsx/header/

    LIBS += -LC:/3rdparty/QXlsx-master/build/ -lQXlsxQt6 # Path to libQXlsxQt6.dll
}
