cmake_minimum_required(VERSION 3.5)

project(Source
    VERSION 0.1
    DESCRIPTION "Source"
    LANGUAGES CXX
)

# Сложный многопоточный tcp сервер + tcp клиент
add_subdirectory(tcp-client-complex)
add_subdirectory(tcp-server-complex)

# Простой tcp сервер + простой tcp клиент
#add_subdirectory(tcp-client-simple)
#add_subdirectory(tcp-server-simple)

# Сложный многопоточный udp сервер + udp клиент с ожиданием
#add_subdirectory(udp-client-complex)
#add_subdirectory(udp-server-complex)

# Простой udp сервер + простой udp клиент
#add_subdirectory(udp-client-simple)
#add_subdirectory(udp-server-simple)

# Сложный многопоточный web сервер
#add_subdirectory(web-server-complex)

# Простой web сервер
#add_subdirectory(web-server-simple)
