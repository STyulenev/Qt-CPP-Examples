QMAKE_LIBS += -static -lgomp -lpthread
QMAKE_CXXFLAGS += -msse3 -fopenmp

INCLUDEPATH += \
        $$PWD/logics/include

HEADERS += \
        $$files($$PWD/logics/include/*.h)

SOURCES += \
        $$files($$PWD/logics/*.cpp)
