CMAKE_MINIMUM_REQUIRED(VERSION 3.28)
PROJECT(server)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

set(SOURCES
        main.cpp
        src/ConfigManager.cpp
        src/ConfigObject.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(Qt6 REQUIRED COMPONENTS Core DBus)
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::DBus)
