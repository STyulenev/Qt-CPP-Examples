cmake_minimum_required(VERSION 3.5)

project(Dialog-lib
    VERSION 0.1
    DESCRIPTION "Static library for custom dialogs"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ui)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

file(GLOB dialog-src "include/*.h" "ui/*.ui" "*.cpp")

add_library(${PROJECT_NAME} STATIC ${dialog-src})
add_library(UI::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

if(COMMAND target_precompile_headers)
   target_precompile_headers(${PROJECT_NAME} PUBLIC ./include/DialogData.h)
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
