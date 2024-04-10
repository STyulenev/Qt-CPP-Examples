cmake_minimum_required(VERSION 3.14)

project(Transport-lib
    VERSION 0.1
    DESCRIPTION "Static library for transport data"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Network HttpServer Concurrent REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Network HttpServer Concurrent REQUIRED)

file(GLOB transport-src "include/*.h" "./*.cpp")

add_library(${PROJECT_NAME} STATIC ${transport-src})

target_include_directories(${PROJECT_NAME} PUBLIC
    include
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::HttpServer
    Qt${QT_VERSION_MAJOR}::Concurrent
    Model-lib
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
