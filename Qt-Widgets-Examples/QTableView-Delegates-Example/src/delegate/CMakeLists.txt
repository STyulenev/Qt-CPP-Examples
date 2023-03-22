cmake_minimum_required(VERSION 3.5)

project(Delegate
    VERSION 0.1
    DESCRIPTION "Delegate"
    LANGUAGES CXX)

add_subdirectory(custom-delegates)
add_subdirectory(custom-widgets)
add_subdirectory(simple-delegates)
add_subdirectory(styled-delegates)
