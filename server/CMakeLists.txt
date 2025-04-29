set(SOURCES
        main.cpp
        src/ConfigManager.cpp
        src/ConfigObject.cpp
)
set(HEADERS
        include/ConfigManager.h
        include/ConfigObject.h
)

add_executable(server ${SOURCES} ${HEADERS})

target_include_directories(server PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(server Qt6::Core Qt6::DBus)
