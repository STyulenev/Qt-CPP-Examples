cmake_minimum_required(VERSION 3.5)

project(Controller-lib
    VERSION 0.1
    DESCRIPTION "Static library with controllers"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

file(GLOB controller-src "include/*.h" "./*.cpp")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_library(${PROJECT_NAME} STATIC ${controller-src})
else()
    add_library(${PROJECT_NAME} STATIC ${controller-src})
endif()

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::Core
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
