cmake_minimum_required(VERSION 3.16)

project(Qml-plugin-lib
    VERSION 0.1
    DESCRIPTION "Static library for new Qml plugin"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Gui Qml Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Gui Qml Quick REQUIRED)

set(PROJECT_SOURCES
    ConcretePlugin.h
    ConcretePlugin.cpp

    ../include/IPlugin.h

    resource.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES})
else()
    # ...
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
    "../include"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Qml
    Qt${QT_VERSION_MAJOR}::Quick
)
