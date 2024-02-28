cmake_minimum_required(VERSION 3.5)

project(Git-Example
    VERSION 0.1.0
    DESCRIPTION "Project with examples of interaction between git and cmake"
    HOMEPAGE_URL "https://github.com/STyulenev/Qt-CPP-Examples"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Добавление подмодулей toml и googletest
add_subdirectory(extern/toml11)
add_subdirectory(extern/googletest)

# Загрузить и установить boost 1.81.0
include(FetchContent)
FetchContent_Declare(
    Boost
    GIT_REPOSITORY https://github.com/boostorg/boost.git
    GIT_TAG boost-1.81.0
)
FetchContent_MakeAvailable(Boost)

set(PROJECT_SOURCES
    git.h
    version.h
    main.cpp
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

# Заголовочные файлы
target_include_directories(${PROJECT_NAME} PRIVATE
    extern/toml11
    extern/googletest
    # ...
)

set(BOOST_INCLUDE_LIBRARIES container) # ...
set(BOOST_ENABLE_CMAKE ON)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Boost::container
    # ...
)

# Установить информацию о git
set(PRE_CONFIGURE_FILE "git.h.in")
set(POST_CONFIGURE_FILE "git.h")

include(${CMAKE_SOURCE_DIR}/cmake/git_watcher.cmake)

# Установить информацию о проекте из CMake (версия/название)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/version.h.in
    ${CMAKE_CURRENT_SOURCE_DIR}/version.h
)
