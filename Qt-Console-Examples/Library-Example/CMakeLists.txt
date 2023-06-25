cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(Library-Example
    VERSION 1.0.0
    DESCRIPTION "CMake Shared-Library Tutorial"
    LANGUAGES CXX
)

add_subdirectory(SharedLibrary)
add_subdirectory(ProjectOne)
add_subdirectory(ProjectTwo)
