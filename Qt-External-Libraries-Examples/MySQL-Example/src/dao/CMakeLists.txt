cmake_minimum_required(VERSION 3.5)

project(DAO-lib
    VERSION 0.1
    DESCRIPTION "Static library with classes that allow you to work with the database"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

if (WIN32)
    set(MySQL_INCLUDE_DIR "C:/Program Files/MySQL/MySQL Server 8.0/include")
    set(MySQL_LIBRARY "C:/Program Files/MySQL/MySQL Server 8.0/lib")
    set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "C:/Program Files/MySQL/MySQL Server 8.0/lib")

    find_package(MySQL REQUIRED)
    include_directories("${MySQL_INCLUDE_DIR}")

    message("---> ${MYSQL_LIB}")
elseif()
    message(FATAL_ERROR "---")
endif()

file(GLOB view-src "include/*.h" "*.cpp")

add_library(${PROJECT_NAME} STATIC ${view-src})

target_link_libraries(${PROJECT_NAME} PUBLIC 
    Qt${QT_VERSION_MAJOR}::Core
    Entity-lib

    ${MySQL_LIBRARY}/connection_pool.dll
    ${MySQL_LIBRARY}/libmysql.dll
)

target_include_directories(${PROJECT_NAME} PUBLIC include ${MySQL_INCLUDE_DIR})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
