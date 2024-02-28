cmake_minimum_required(VERSION 3.14)

project(Test-bin
    VERSION 0.1
    DESCRIPTION "Binary with tests"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

if(NOT EXISTS "doctest.h")
    execute_process(COMMAND curl https://raw.githubusercontent.com/onqtam/doctest/master/doctest/doctest.h -o doctest.h args
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/tests)
endif()

file(GLOB tests-src "./*.cpp")

add_executable(${PROJECT_NAME}
    doctest.h
    ${tests-src}
)

target_link_libraries(${PROJECT_NAME}
    Qt${QT_VERSION_MAJOR}::Core
    Logic-lib
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

add_custom_target(Runtime-Test-Bin
    POST_BUILD
    COMMAND ${PROJECT_NAME}
    COMMENT "Run tests after building all targets"
    #VERBATIM
)
