cmake_minimum_required(VERSION 3.5)

project(View-model-lib
    VERSION 0.1
    DESCRIPTION "Static library for View models (+ delegates and models)"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ui)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

file(GLOB model-src "model/*.h" "model/*.cpp")
file(GLOB delegate-src "delegate/*.h" "delegate/*.cpp")
file(GLOB view-model-src "include/*.h" "*.cpp")

add_library(${PROJECT_NAME} STATIC ${model-src} ${delegate-src} ${view-model-src})

target_link_libraries(${PROJECT_NAME} PUBLIC Qt${QT_VERSION_MAJOR}::Widgets)

target_include_directories(${PROJECT_NAME} PUBLIC include delegate model)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
