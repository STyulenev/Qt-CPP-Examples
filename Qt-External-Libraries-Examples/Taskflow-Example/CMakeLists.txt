cmake_minimum_required(VERSION 3.14)

project(Taskflow-Example
    VERSION 0.1
    DESCRIPTION "Project with an example of using Qt and Taskflow"
    HOMEPAGE_URL "https://github.com/STyulenev/Qt-CPP-Examples"
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic -Wno-deprecated-declarations -fstrict-aliasing -pedantic-errors -Wno-unused-variable")

set(QT_CREATOR_SKIP_CONAN_SETUP ON)

#Для корректного поиска файлов FindXXX.cmake добавляем директорию сборки в MODULE_PATH
#list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})
#list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_BINARY_DIR})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

find_package(Taskflow 3.10.0 REQUIRED)

# Taskflow использует зарезервированные слова из Qt
# Запрещаем использование signals, emit и т.д.
add_definitions(-DQT_NO_KEYWORDS)

add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core

    Taskflow::Taskflow
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
