cmake_minimum_required(VERSION 3.5)

project(Test-Lib
    VERSION 0.1
    DESCRIPTION "Static library with tests"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Test REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Test REQUIRED)

file(GLOB tests-src "include/*.h" "./*.cpp")

add_library(${PROJECT_NAME} STATIC ${tests-src})

target_link_libraries(${PROJECT_NAME} PUBLIC
	Qt${QT_VERSION_MAJOR}::Test
	Logics-lib
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
