cmake_minimum_required(VERSION 3.5)

project(SQLite-Example VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

find_library(SQLITE3_LIBRARIES REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui

        DAO.h
        DAO.cpp

        Person.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SQLite-Example
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(SQLite-Example
        ${PROJECT_SOURCES}
    )
endif()

include_directories(${SQLite3_INCLUDE_DIRS})

target_link_libraries(SQLite-Example PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    ${SQLITE3_LIBRARIES}
)
