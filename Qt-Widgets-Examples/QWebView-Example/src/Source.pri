INCLUDEPATH += \
        $$PWD/view/include/* \
		$$PWD/print/include/*

HEADERS += \
        $$files($$PWD/view/include/*.h) \
		$$files($$PWD/print/include/*.h)

SOURCES += \
        $$files($$PWD/view/*.cpp) \
		$$files($$PWD/print/*.cpp)

FORMS += \
        $$files($$PWD/view/ui/*.ui)
