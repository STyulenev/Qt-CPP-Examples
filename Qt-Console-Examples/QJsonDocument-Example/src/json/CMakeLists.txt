cmake_minimum_required(VERSION 3.5)

project(Json-lib
    VERSION 0.1
    DESCRIPTION "Static library with an example of working with QJson"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

file(GLOB json-src "include/*.h" "./*.cpp")

add_library(${PROJECT_NAME} STATIC ${json-src})

target_link_libraries(${PROJECT_NAME} PUBLIC Qt${QT_VERSION_MAJOR}::Core)

target_include_directories(${PROJECT_NAME} PUBLIC include)
