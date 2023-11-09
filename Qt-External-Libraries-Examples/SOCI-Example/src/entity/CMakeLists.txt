cmake_minimum_required(VERSION 3.5)

project(Entity-lib
    VERSION 0.1
    DESCRIPTION "Entities for Data Access Object"
    LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

set(PostgreSQL_ADDITIONAL_VERSIONS "16")

find_package(PostgreSQL REQUIRED)
if (PostgreSQL_FOUND)
    message("Version = ${PostgreSQL_VERSION_STRING}")
    message("Path = ${PostgreSQL_INCLUDE_DIRS}")
    message("Lib = ${PostgreSQL_LIBRARIES}")
    include_directories(${PROJECT_NAME} PUBLIC ${PostgreSQL_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "error")
endif()

# conan install . --output-folder=build --build=missing
#include_directories("C:/3rdparty/soci-master/build/include")
#include_directories("C:/3rdparty/soci-master/include/")

file(GLOB entity-src "include/*.h" "./*.cpp")

add_library(${PROJECT_NAME} STATIC ${entity-src})

target_include_directories(${PROJECT_NAME} PUBLIC
    include
    "C:/3rdparty/soci-master/build/include"
    "C:/3rdparty/soci-master/include/"
    ${PostgreSQL_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::Core

    "C:/3rdparty/soci-master/build/bin/libsoci_core_4_1.dll"
    "C:/3rdparty/soci-master/build/bin/libsoci_empty_4_1.dll"
    "C:/3rdparty/soci-master/build/bin/libsoci_odbc_4_1.dll"
    "C:/3rdparty/soci-master/build/bin/libsoci_postgresql_4_1.dll"

    ${PostgreSQL_LIBRARIES}
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

