cmake_minimum_required(VERSION 3.5)

project(Source
    VERSION 0.1
    DESCRIPTION "Source"
    LANGUAGES CXX
)

add_subdirectory(udp-client-simple)
add_subdirectory(udp-server-simple)
#add_subdirectory(web-server-complex)
#add_subdirectory(web-server-simple)
