cmake_minimum_required(VERSION 3.5)

project(DAO-lib
    VERSION 0.1
    DESCRIPTION "Static library with classes that allow you to work with the database"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

find_library(SQLITE3_LIBRARIES sqlite3 REQUIRED)

file(GLOB dao-src "include/*.h" "*.cpp")

add_library(${PROJECT_NAME} STATIC ${dao-src})

target_link_libraries(${PROJECT_NAME} PUBLIC 
    Qt${QT_VERSION_MAJOR}::Core
    Entity-lib
    ${SQLITE3_LIBRARIES}
)

include_directories(${SQLite3_INCLUDE_DIRS})

target_include_directories(${PROJECT_NAME} PUBLIC include)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
