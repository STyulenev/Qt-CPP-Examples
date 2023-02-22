cmake_minimum_required(VERSION 3.5)

project(QXlsx-Example
    VERSION 0.1
    DESCRIPTION "Project with sample QXlsx + QTableView"
    LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

include_directories("C:/3rdparty/QXlsx-master/QXlsx/header") # Path to QXlsx headers folder

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        TableViewModel.h
        TableViewModel.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QXlsx-Example
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(QXlsx-Example PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets

    "C:/3rdparty/QXlsx-master/build/libQXlsxQt6.dll" # Path to QXlsx .dll or .so
    )
