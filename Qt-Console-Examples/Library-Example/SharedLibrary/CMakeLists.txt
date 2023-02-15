cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(SharedLibrary
    VERSION 1.0.0
    DESCRIPTION "SharedLibrary"
    LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

set(export_file_name
    include/SharedDll.h
    include/SharedDllGlobal.h
)

add_library(SharedLibrary SHARED
    SharedDll.cpp

    ${export_file_name}
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(${PROJECT_NAME} PRIVATE SHARED_LIBRARY)

target_include_directories(${PROJECT_NAME} PUBLIC include)

