cmake_minimum_required(VERSION 3.5)

project(QxORM-Example-entity
    VERSION 0.1
    DESCRIPTION "DAO"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Sql REQUIRED)

#include(C:/Work/CurrentExample/QxOrm-master/QxOrm.cmake)

file(GLOB entity-src "include/*.h" "./*.cpp")

add_library(${PROJECT_NAME} STATIC ${entity-src})

target_compile_definitions(${PROJECT_NAME} PRIVATE -D_QXORM_EXAMPLE)

include_directories("C:/Work/CurrentExample/QxOrm-master/include/")

if(COMMAND target_precompile_headers)
   target_precompile_headers(${PROJECT_NAME} PUBLIC ./include/precompiled.h)
endif() # (COMMAND target_precompile_headers)


target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Sql

    "C:/Work/CurrentExample/QxOrm-master/lib/libQxOrmd.dll"
)

target_include_directories(${PROJECT_NAME} PUBLIC include)
