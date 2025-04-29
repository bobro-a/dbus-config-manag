set(SOURCES
        main.cpp
        src/Application.cpp
)

set(HEADERS
        include/Application.h
)

add_executable(app ${SOURCES} ${HEADERS})

target_include_directories(app PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(app Qt6::Core Qt6::DBus)
