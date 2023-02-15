cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(ProjectTwo
    VERSION 1.0.0
    DESCRIPTION "ProjectTwo"
    LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin" )

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

set(PROJECT_SOURCES
        main.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ProjectTwo
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
endif()

include_directories( "../SharedLibrary/include" )

target_link_libraries(ProjectTwo PRIVATE Qt${QT_VERSION_MAJOR}::Core SharedLibrary)


