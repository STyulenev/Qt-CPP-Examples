INCLUDEPATH += \
        $$PWD/validator/include/ \
        $$PWD/view/include/
        

HEADERS += \
        $$files($$PWD/validator/include/*.h) \
        $$files($$PWD/view/include/*.h)

SOURCES += \
        $$files($$PWD/validator/*.cpp) \
        $$files($$PWD/view/*.cpp)

FORMS += \
        $$files($$PWD/view/ui/*.ui)
