cmake_minimum_required(VERSION 3.5)

project(Protobuf-library
    VERSION 0.1
    DESCRIPTION "Library with auto-generated protobuf classes"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

if (WIN32)
    set(PROTOBUF_INCLUDE_PATH "C:/3rdparty/protobuf-3.21.12/src")
    set(PROTOBUF_LIBRARY_PATH "C:/3rdparty/protobuf-3.21.12-build")

    set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} ${PROTOBUF_INCLUDE_PATH}) # If paths to environment variables are not added
    set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} ${PROTOBUF_LIBRARY_PATH})

    include(FindProtobuf)
    if(Protobuf_FOUND)
        message("-- Protobuf ${Protobuf_VERSION} found")
    else()
        message("-- Protobuf not found")
        return()
    endif()

    find_package(Protobuf ${Protobuf_VERSION} REQUIRED)
    include_directories(${PROTOBUF_INCLUDE_DIR})

    set(PROTO_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/generated")
    file(GLOB proto_files "${CMAKE_CURRENT_SOURCE_DIR}/*.proto")

    if (NOT EXISTS ${PROTO_OUTPUT_DIR})
        file(MAKE_DIRECTORY ${PROTO_OUTPUT_DIR})
    endif()

    foreach(proto_file ${proto_files}) # auto-generated protobuf classes
        get_filename_component(base_name ${proto_file} NAME_WE)
        if ((NOT EXISTS "${PROTO_OUTPUT_DIR}/${base_name}.pb.cc") OR (NOT EXISTS "${PROTO_OUTPUT_DIR}/${base_name}.pb.h"))
            message("-- Generate protobuf files for ${base_name}")
            execute_process(COMMAND ${PROTOBUF_LIBRARY_PATH}/protoc.exe -I=${CMAKE_CURRENT_SOURCE_DIR} --cpp_out=${PROTO_OUTPUT_DIR} ${proto_file})
        endif()
    endforeach()
elseif(UNIX)
    include(FindProtobuf)
    find_package(Protobuf REQUIRED)
    include_directories(${PROTOBUF_INCLUDE_DIR})
    # ...
endif()

file(GLOB proto-src "${PROTO_OUTPUT_DIR}/*.pb.h" "${PROTO_OUTPUT_DIR}/*.pb.cc")

add_library(${PROJECT_NAME} STATIC ${proto-src})

target_link_libraries(${PROJECT_NAME} PUBLIC
    protobuf::libprotoc        # or ${Protobuf_PROTOC_LIBRARY}
    protobuf::libprotobuf      # or ${Protobuf_LIBRARY}
    protobuf::libprotobuf-lite # or ${Protobuf_LITE_LIBRARY}
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROTO_OUTPUT_DIR})
