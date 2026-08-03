cmake_minimum_required(VERSION 3.1)

project(Catch2-bin
    VERSION 0.1
    DESCRIPTION "Directory for Catch2"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

file(GLOB test-src "./*.cpp")

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.15.3
)

FetchContent_MakeAvailable(Catch2)

add_executable(${PROJECT_NAME} ${test-src})

target_link_libraries(${PROJECT_NAME} PRIVATE
    Logic-lib
    Catch2::Catch2
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
)
