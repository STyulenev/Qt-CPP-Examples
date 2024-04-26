cmake_minimum_required(VERSION 3.1)

project(Boost-Tests-bin
    VERSION 0.1
    DESCRIPTION "Directory for Boost tests"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DBOOST_ALL_DYN_LINK=1 -DBOOST_ALL_NO_LIB=1)

if(WIN32)
    set(BOOST_ROOT "C:/3rdparty/boost_1_85_0") # Path to Boost
endif()

find_package(Boost 1.85 REQUIRED COMPONENTS ${BOOST_COMPONENTS} REQUIRED)

if(Boost_FOUND)
    include_directories(include ${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
else()
    message(FATAL_ERROR "BOOST NOT FOUND")
endif ()

file(GLOB test-src "./*.cpp")

enable_testing()

add_executable(${PROJECT_NAME} ${test-src})

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

enable_testing()

target_link_libraries(${PROJECT_NAME} PRIVATE
    Logic-lib
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
)

