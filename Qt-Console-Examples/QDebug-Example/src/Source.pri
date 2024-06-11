INCLUDEPATH += \
        $$PWD \
        $$PWD/model/include/ \
		$$PWD/setting/include/

HEADERS += \
        $$files($$PWD/model/include/*.h) \
		$$files($$PWD/setting/include/*.h)

SOURCES += \
        $$files($$PWD/model/*.cpp) \
		$$files($$PWD/setting/*.cpp)
