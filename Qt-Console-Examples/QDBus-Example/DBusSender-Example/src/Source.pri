DBUS_ADAPTORS += $$PWD/controller/org.example.message.xml

INCLUDEPATH += \
        $$PWD \
        $$PWD/controller \
        $$PWD/controller/include/

HEADERS += \
        $$files($$PWD/controller/include/*.h)

SOURCES += \
        $$files($$PWD/controller/*.cpp)
