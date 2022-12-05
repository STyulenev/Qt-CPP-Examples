cmake_minimum_required(VERSION 3.5)

project(ExampleQTableViewDelegates
    VERSION 0.1
    DESCRIPTION "Project with sample delegates for QTableView"
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

set(PROJECT_SOURCES
    main.cpp

    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    res.qrc
)

file(GLOB simple-delegates-src "simple-delegates/*.h" "simple-delegates/*.cpp")
file(GLOB styled-delegates-src "styled-delegates/*.h" "styled-delegates/*.cpp")
file(GLOB view-model-src "view-model/*.h" "view-model/*.cpp")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ExampleQTableViewDelegates
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${simple-delegates-src}
        ${styled-delegates-src}
        ${view-model-src}
        )
endif()

target_link_libraries(ExampleQTableViewDelegates PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

