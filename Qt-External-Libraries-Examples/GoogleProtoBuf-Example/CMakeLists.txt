cmake_minimum_required(VERSION 3.5)

project(GoogleProtoBuf-Example
    VERSION 0.1
    DESCRIPTION "Project with sample Google Protocol Buffers library"
    LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

if (WIN32)
    set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:/3rdparty/protobuf-3.21.12/src")
    set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:/3rdparty/protobuf-3.21.12-build")

    include(FindProtobuf)
    find_package(Protobuf REQUIRED)

    execute_process(COMMAND C:/3rdparty/protobuf-3.21.12-build/protoc.exe -I=C:/Work/TestProtoBuf/ --cpp_out=C:/Work/TestProtoBuf/generate/ C:/Work/TestProtoBuf/addressbook.proto)
elseif(UNIX)
    include(FindProtobuf)
    find_package(Protobuf REQUIRED)
    include_directories(${PROTOBUF_INCLUDE_DIR})
endif()

file(GLOB proto-src "generate/*.pb.h" "generate/*.pb.cc")

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${proto-src}
    )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets

    protobuf::libprotoc
    protobuf::libprotobuf
    protobuf::libprotobuf-lite
)
