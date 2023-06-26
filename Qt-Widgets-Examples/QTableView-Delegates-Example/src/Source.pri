include(delegate/custom-delegates/SustomDelegates.pri)
include(delegate/custom-widgets/CustomWidgets.pri)
include(delegate/simple-delegates/SimpleDelegates.pri)
include(delegate/styled-delegates/StyledDelegates.pri)

INCLUDEPATH += \
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
