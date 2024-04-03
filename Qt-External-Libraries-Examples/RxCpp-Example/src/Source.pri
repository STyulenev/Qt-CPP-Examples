INCLUDEPATH += \
        $$PWD \
        $$PWD/model/include/ \
        $$PWD/view/include/

HEADERS += \
        $$files($$PWD/model/include/*.h) \
        $$files($$PWD/view/include/*.h)

SOURCES += \
        $$files($$PWD/model/*.cpp) \
        $$files($$PWD/view/*.cpp)
		
FORMS += \
        $$files($$PWD/view/ui/*.ui)

win32 {
    ## Windows common build here
    INCLUDEPATH += C:/3rdparty/RxCpp/build/lib/include # RxCpp include folder
}
