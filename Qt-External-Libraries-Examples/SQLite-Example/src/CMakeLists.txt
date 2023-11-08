cmake_minimum_required(VERSION 3.5)

project(Source
    VERSION 0.1
    DESCRIPTION "Source"
    LANGUAGES CXX
)

add_subdirectory(dao)
add_subdirectory(entity)
add_subdirectory(view)
