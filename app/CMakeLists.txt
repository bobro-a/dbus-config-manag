CMAKE_MINIMUM_REQUIRED(VERSION 3.28)
PROJECT(confManagerApplication1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core DBus)

set(SOURCES
        main.cpp
        src/Application.cpp
)

set(HEADERS
        include/Application.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::DBus)
