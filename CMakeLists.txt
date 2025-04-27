CMAKE_MINIMUM_REQUIRED(VERSION 3.28)
PROJECT(dbus-config-manag)

set(CMAKE_CXX_STANDARD 20)
add_executable(${PROJECT_NAME}
        src/main.cpp
        src/ConfigManager.cpp
)

find_package(Qt6 REQUIRED COMPONENTS Core DBus)
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::DBus)
