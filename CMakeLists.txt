CMAKE_MINIMUM_REQUIRED(VERSION 3.28)
PROJECT(DbusConfigurationManager)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Core DBus)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(server)
add_subdirectory(app)