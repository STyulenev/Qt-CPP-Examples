cmake_minimum_required(VERSION 3.5)

project(web-server-complex
    VERSION 0.1
    DESCRIPTION "An example of creating a complex web server using Boost.Asio"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost 1.85 REQUIRED COMPONENTS ${BOOST_COMPONENTS} REQUIRED)

#Для корректного поиска файлов FindXXX.cmake добавляем директорию сборки в MODULE_PATH
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB web-server-src "*.h" "*.cpp")

add_executable(${PROJECT_NAME} ${web-server-src})

target_link_libraries(${PROJECT_NAME} PUBLIC 
    boost::boost
)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32)
    target_link_libraries(${PROJECT_NAME} PRIVATE mswsock)
endif()

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
