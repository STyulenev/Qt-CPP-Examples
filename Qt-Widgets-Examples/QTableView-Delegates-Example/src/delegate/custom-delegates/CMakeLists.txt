cmake_minimum_required(VERSION 3.5)

project(Custom-delegate-lib
    VERSION 0.1
    DESCRIPTION "Static library with custom delegates"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

file(GLOB custom-delegates-src "include/*.h" "./*.cpp")

add_library(${PROJECT_NAME} STATIC ${custom-delegates-src} ${custom-widgets-src})
add_library(Delegates::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
    include
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::Widgets
    Custom-widget-lib
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
