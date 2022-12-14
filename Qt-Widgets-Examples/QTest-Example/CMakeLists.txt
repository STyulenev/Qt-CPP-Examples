cmake_minimum_required(VERSION 3.5)

project(QTest-Example
    VERSION 0.1
    DESCRIPTION "Project with sample qtest"
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

add_subdirectory(src)
add_subdirectory(tests)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QTest-Example
        MANUAL_FINALIZATION
        main.cpp
    )
endif()

target_link_libraries(QTest-Example PRIVATE
    QTest-Example-Test-Lib
)
