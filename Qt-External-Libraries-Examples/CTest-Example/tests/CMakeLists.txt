cmake_minimum_required(VERSION 3.1)

project(CTests-bin
    VERSION 0.1
    DESCRIPTION "Directory for CTests"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

file(GLOB test-src "./*.cpp")

include(CTest)

add_executable(${PROJECT_NAME} ${test-src})

enable_testing()

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PRIVATE
    Logic-lib
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
)
