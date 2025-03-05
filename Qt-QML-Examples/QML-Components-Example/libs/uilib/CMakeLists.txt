cmake_minimum_required(VERSION 3.5)

project(UI-lib
    VERSION 0.1
    DESCRIPTION "Static library for UI"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Concurrent Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Concurrent Quick REQUIRED)

file(GLOB qml-controller-src "src/include/*.h" "src/*.cpp")

add_library(${PROJECT_NAME} STATIC ${qml-controller-src} uilib_resource.qrc)

target_include_directories(${PROJECT_NAME} PUBLIC src/include)

target_link_libraries(${PROJECT_NAME} PUBLIC 
    Qt${QT_VERSION_MAJOR}::Concurrent
    Qt${QT_VERSION_MAJOR}::Quick
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
