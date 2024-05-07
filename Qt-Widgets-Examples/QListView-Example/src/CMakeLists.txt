cmake_minimum_required(VERSION 3.5)

project(Source
    VERSION 0.1
    DESCRIPTION "Source"
    LANGUAGES CXX
)

add_subdirectory(delegate)
add_subdirectory(view)
add_subdirectory(view-model)
