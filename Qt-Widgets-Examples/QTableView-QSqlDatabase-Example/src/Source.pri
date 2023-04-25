QT += sql

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
