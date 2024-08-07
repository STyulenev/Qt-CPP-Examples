cmake_minimum_required(VERSION 3.5)

project(QTextEdit-QSyntaxHighlighter-Example
    VERSION 0.1
    DESCRIPTION "Project with sample QTextEdit and QSyntaxHighlighter (on SQL editor example)"
    HOMEPAGE_URL "https://github.com/STyulenev/Qt-CPP-Examples"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

add_subdirectory(src)

set(PROJECT_SOURCES
    main.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
elseif(${QT_VERSION_MAJOR} EQUAL 5)
    add_executable(${PROJECT_NAME}
        ${PROJECT_SOURCES}
    )
elseif(${QT_VERSION_MAJOR} LESS 5)
    message(FATAL_ERROR "Qt version too old")
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    View-lib
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
