cmake_minimum_required(VERSION 3.20)

project(
    AIEngine
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Core engine library
add_library(ai_core STATIC
    src/core/Engine.cpp
)

target_include_directories(ai_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(ai_core PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

# CLI executable
add_executable(ai
    src/main.cpp
)

target_link_libraries(ai
    PRIVATE ai_core
)

target_compile_options(ai PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)