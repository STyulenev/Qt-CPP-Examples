cmake_minimum_required(VERSION 3.5)

project(Print-lib
    VERSION 0.1
    DESCRIPTION "Static library for reports"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS WebKit WebKitWidgets PrintSupport REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS WebKit WebKitWidgets PrintSupport REQUIRED)

file(GLOB print-src "include/*.h" "./*.cpp")

add_library(${PROJECT_NAME} STATIC ${print-src})

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::WebKit
    Qt${QT_VERSION_MAJOR}::WebKitWidgets
    Qt${QT_VERSION_MAJOR}::PrintSupport
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
