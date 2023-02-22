cmake_minimum_required(VERSION 3.5)

project(POCO-Example
    VERSION 0.1
    DESCRIPTION "Project with sample POCO"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    POCO-Example-server
)
