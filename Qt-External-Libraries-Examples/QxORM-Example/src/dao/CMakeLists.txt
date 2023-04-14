cmake_minimum_required(VERSION 3.5)

project(DAO-lib
    VERSION 0.1
    DESCRIPTION "DAO"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

file(GLOB dao-src "include/*.h" "./*.cpp")

add_library(${PROJECT_NAME} STATIC ${dao-src})

target_link_libraries(${PROJECT_NAME} PUBLIC
    Entity-lib
)

target_include_directories(${PROJECT_NAME} PUBLIC include)
