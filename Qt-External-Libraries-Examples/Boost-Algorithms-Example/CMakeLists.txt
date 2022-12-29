cmake_minimum_required(VERSION 3.5)

project(Boost-Algorithm-Example
    VERSION 0.1
    DESCRIPTION "Project with sample Boost Algorithm"
    LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

#set(Boost_DEBUG ON)
#find_package(Boost COMPONENTS ALL)
set(BOOST_INCLUDE_LIBRARIES algorithm container)
set(BOOST_ENABLE_CMAKE ON)

include(FetchContent)
FetchContent_Declare(
  Boost
  GIT_REPOSITORY https://github.com/boostorg/boost.git
  GIT_TAG boost-1.81.0
)
FetchContent_MakeAvailable(Boost)

add_executable(${PROJECT_NAME}
    SearchingAlgorithms.h
    SearchingAlgorithms.cpp
    main.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::Core
    Boost::container
    Boost::algorithm
)

