INCLUDEPATH += \
        $$PWD/dialog/include/ \
	$$PWD/view/include/

PRECOMPILED_HEADER = $$PWD/dialog/include/DialogData.h

HEADERS += \
	$$files($$PWD/dialog/include/*.h) \
        $$files($$PWD/view/include/*.h)

SOURCES += \
	$$files($$PWD/dialog/*.cpp) \
        $$files($$PWD/view/*.cpp)

FORMS += \
	$$files($$PWD/dialog/ui/*.ui) \
        $$files($$PWD/view/ui/*.ui)
