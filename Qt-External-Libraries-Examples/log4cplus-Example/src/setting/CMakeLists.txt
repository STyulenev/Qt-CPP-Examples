cmake_minimum_required(VERSION 3.5)

project(Setting-lib
    VERSION 0.1
    DESCRIPTION "Static library for setting classes"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

find_package(log4cplus 2.1.2 REQUIRED)
find_package(SQLite3 3.47.0 REQUIRED)

file(GLOB settings-src "include/*.h" "./*.cpp")

add_library(${PROJECT_NAME} STATIC ${settings-src})

target_include_directories(${PROJECT_NAME} PUBLIC
    include
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::Core

    log4cplus::log4cplus
    SQLite::SQLite3
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
