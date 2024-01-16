INCLUDEPATH += \
        $$PWD/view/include/ \
        $$PWD/wizard-page/include/

HEADERS += \
        $$files($$PWD/view/include/*.h) \
        $$files($$PWD/wizard-page/include/*.h)

SOURCES += \
        $$files($$PWD/view/*.cpp) \
        $$files($$PWD/wizard-page/*.cpp)

FORMS += \
        $$files($$PWD/view/ui/*.ui) \ 
        $$files($$PWD/wizard-page/ui/*.ui)
