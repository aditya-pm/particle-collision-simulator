cmake_minimum_required(VERSION 3.12)
project(Particles)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Raylib dependency
find_package(raylib REQUIRED)

# Include headers
include_directories(include)

file(GLOB SOURCES src/*.c)

add_executable(${PROJECT_NAME} ${SOURCES})

# Link raylib
target_link_libraries(${PROJECT_NAME} raylib)

# Copy assets folder next to executable after build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
