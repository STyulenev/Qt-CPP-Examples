cmake_minimum_required(VERSION 3.5)

project(Model-lib
    VERSION 0.1
    DESCRIPTION "Static library for View models"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

file(GLOB model-src "include/*.h" "./*.cpp")

add_library(${PROJECT_NAME} STATIC ${model-src})

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt6::Quick
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
