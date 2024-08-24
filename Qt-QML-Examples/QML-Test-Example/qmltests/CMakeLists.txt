cmake_minimum_required(VERSION 3.5)

project(QMLTest
    VERSION 0.1
    DESCRIPTION "Subroject with tests"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS QuickTest Qml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS QuickTest Qml)

# no need to copy around qml test files for shadow builds - just set the respective define
add_definitions(-DQUICK_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB_RECURSE QML_FILES "tst_*.qml")
add_custom_target(qmlfiles SOURCES ${QML_FILES})

add_executable(${PROJECT_NAME}
    main.cpp
    ${CMAKE_SOURCE_DIR}/resource.qrc
)

# target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME}
  -import ${CMAKE_SOURCE_DIR}/qml
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::QuickTest
    Qt${QT_VERSION_MAJOR}::Qml
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

