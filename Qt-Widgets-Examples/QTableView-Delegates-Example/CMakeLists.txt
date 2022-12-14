cmake_minimum_required(VERSION 3.5)

project(QTableView-Delegates-Example
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

add_subdirectory(custom-widgets) 
add_subdirectory(custom-delegates) 
add_subdirectory(simple-delegates) 
add_subdirectory(styled-delegates)
add_subdirectory(view-model)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        )
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC
	Custom-delegates
	Simple-delegates
	Styled-delegates
	View-models
)

