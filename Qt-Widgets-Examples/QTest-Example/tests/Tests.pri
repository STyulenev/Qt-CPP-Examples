QT += testlib

DEFINES += TEST_MODULE

INCLUDEPATH += $$PWD/include/

HEADERS += $$files($$PWD/include/*.h)

SOURCES += $$files($$PWD/*.cpp)
