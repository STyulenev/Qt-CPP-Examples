cmake_minimum_required(VERSION 3.5)

project(QxORM-Example
    VERSION 0.1
    DESCRIPTION "Project with sample QxORM library"
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

if(WIN32)
  include("C:/3rdparty/QxOrm-master/QxOrm.cmake") ## Path to QxORM cmake file
else()
  message(FATAL_ERROR "Unknown system." )
endif()

add_subdirectory(src)

set(PROJECT_SOURCES
    main.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    View-lib
)

