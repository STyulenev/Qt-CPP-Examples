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

if(WIN32)
    list(APPEND CMAKE_PREFIX_PATH "C:/3rdparty/Celero-master/build/install")
    set(Celero_INCLUDE_DIR "C:/3rdparty/Celero-master/build/install/include")

    find_package(Celero) # REQUIRED

    if (Celero_FOUND)
        message("-- Celero has found - ${Celero_VERSION}")
    else()
        message(FATAL_ERROR "-- Celero not found")
    endif()
elseif()
    message(FATAL_ERROR "-- Needed setting for current OS")
endif(WIN32)

file(GLOB tests-src "./*.cpp")

add_executable(${PROJECT_NAME}
    ${tests-src}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${Celero_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
    Qt${QT_VERSION_MAJOR}::Core

    Logic-lib

    "C:/3rdparty/Celero-master/build/install/lib/libcelero.dll"
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

add_custom_target(Runtime-Test-Bin
    POST_BUILD
    COMMAND ./${PROJECT_NAME}
    COMMENT "Run tests after building all targets"
    #VERBATIM
)
