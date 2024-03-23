cmake_minimum_required(VERSION 3.14)

project(Vcpkg-Example
    VERSION 0.1
    DESCRIPTION "Project with an example of using Qt and Vcpkg"
    HOMEPAGE_URL "https://github.com/STyulenev/Qt-CPP-Examples"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)

set(CMAKE_TOOLCHAIN_FILE "C:/3rdparty/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_TARGET_TRIPLET "x64-mingw-dynamic")
set(VCPKG_DEFAULT_TRIPLET "x64-mingw-dynamic")
set(VCPKG_DEFAULT_HOST_TRIPLET "x64-mingw-dynamic")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

# or ./vcpkg install boost-date-time
include("C:/3rdparty/vcpkg/scripts/buildsystems/vcpkg.cmake")

if(WIN32)
    set(Boost_USE_STATIC_LIBS ON)
else()
    set(Boost_USE_STATIC_LIBS OFF)
    add_definitions(-DBOOST_ALL_DYN_LINK)
endif()

find_package(Boost REQUIRED COMPONENTS date_time)

include_directories(${Boost_INCLUDE_DIRS})

set(PROJECT_SOURCES
    main.cpp
    vcpkg.json
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(${PROJECT_NAME}
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core

    Boost::boost
    Boost::date_time
    #${Boost_LIBRARIES}
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
