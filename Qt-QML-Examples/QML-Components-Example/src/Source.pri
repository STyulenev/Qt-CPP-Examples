INCLUDEPATH += \
        $$PWD/qml-components/include/ \
        $$PWD/qml-controllers/include/

HEADERS += \
        $$files($$PWD/qml-components/include/*.h) \
        $$files($$PWD/qml-controllers/include/*.h)

SOURCES += \
        $$files($$PWD/qml-components/*.cpp) \
        $$files($$PWD/qml-controllers/*.cpp)
