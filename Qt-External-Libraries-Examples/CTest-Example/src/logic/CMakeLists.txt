cmake_minimum_required(VERSION 3.5)

project(Logic-lib
    VERSION 0.1
    DESCRIPTION "Static library for logic"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Core REQUIRED)

file(GLOB logic-src "include/*.h" "./*.cpp")

add_library(${PROJECT_NAME} STATIC ${logic-src})

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt5::Core
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
