cmake_minimum_required(VERSION 3.16)

target_sources(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/web_server.h)
target_sources(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/web_server.cpp)

add_subdirectory(handlers)
