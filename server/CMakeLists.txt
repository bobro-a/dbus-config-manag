CMAKE_MINIMUM_REQUIRED(VERSION 3.28)
PROJECT(server)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core DBus)

set(SOURCES
        main.cpp
        src/ConfigManager.cpp
        src/ConfigObject.cpp
)
set(HEADERS
        include/ConfigManager.h
        include/ConfigObject.h
        ../Constants.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/../)

target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::DBus)
