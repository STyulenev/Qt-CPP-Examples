win32 {
    ## Windows common build here
    INCLUDEPATH += C:/3rdparty/protobuf-3.21.12/src # protobuf include folder

    LIBS += -Wl,-rpath,C:/3rdparty/protobuf-3.21.12-build/ -LC:/3rdparty/protobuf-3.21.12-build/ # protobuf libs folder
    LIBS += -lprotoc -lprotoc -lprotobuf -lprotobuf-lite

    PROTOS = $$files($$PWD/*.proto)
    PROTOBUF_LIBRARY_PATH = C:/3rdparty/protobuf-3.21.12-build
    PROTO_OUTPUT_DIR = $$PWD/generated

    for (proto, PROTOS) {
        system("$${PROTOBUF_LIBRARY_PATH}/protoc.exe -I=$$PWD --cpp_out=$${PROTO_OUTPUT_DIR} $${proto}")
    }

    INCLUDEPATH += $$PWD/generated

    HEADERS += $$files($${PROTO_OUTPUT_DIR}/*.pb.h)

    SOURCES += $$files($${PROTO_OUTPUT_DIR}/*.pb.cc)
}
