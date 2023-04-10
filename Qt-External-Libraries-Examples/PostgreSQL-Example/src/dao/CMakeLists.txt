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

find_package(PostgreSQL REQUIRED)
if (PostgreSQL_FOUND)
    message("Version = ${PostgreSQL_VERSION_STRING}")
    message("Path = ${PostgreSQL_INCLUDE_DIRS}")
    include_directories(${PROJECT_NAME} PUBLIC ${PostgreSQL_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "error")
endif()

file(GLOB view-src "include/*.h" "*.cpp")

add_library(${PROJECT_NAME} STATIC ${view-src})

target_link_libraries(${PROJECT_NAME} PUBLIC 
    Qt${QT_VERSION_MAJOR}::Core
    Entity-lib
    ${PostgreSQL_LIBRARIES}
)

target_include_directories(${PROJECT_NAME} PUBLIC include ${PostgreSQL_INCLUDE_DIRS})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
