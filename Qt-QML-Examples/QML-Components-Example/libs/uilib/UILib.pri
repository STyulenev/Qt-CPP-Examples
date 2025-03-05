INCLUDEPATH += \
        $$PWD/src/include/

QML_IMPORT_PATH += $$PWD/qml

HEADERS += \
        $$files($$PWD/src/include/*.h)

SOURCES += \
        $$files($$PWD/src/*.cpp)

RESOURCES += \
        $$PWD/uilib_resource.qrc
