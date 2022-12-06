cmake_minimum_required(VERSION 3.5)

project(QTableView-ProxyModel-Example
    VERSION 0.1
    DESCRIPTION "Project with sample proxy model for QTableView"
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
)

file(GLOB view-model-src "view-model/*.h" "view-model/*.cpp")
file(GLOB proxy-model-src "proxy-model/*.h" "proxy-model/*.cpp")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${view-model-src}
        ${proxy-model-src}
    )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
