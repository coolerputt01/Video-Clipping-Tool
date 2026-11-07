
cmake_minimum_required(VERSION 3.20)

project(
    TopTheGoalsEngine
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable CTest
include(CTest)

# Core library
add_library(ai_core STATIC
    src/core/Engine.cpp
    src/core/Job.cpp
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

# CLI
add_executable(ai
    src/main.cpp
)

target_link_libraries(ai PRIVATE ai_core)

# Automated tests
if(BUILD_TESTING)
    add_executable(ai_core_tests
        tests/core_tests.cpp
    )

    target_link_libraries(
        ai_core_tests
        PRIVATE ai_core
    )

    add_test(
        NAME core_tests
        COMMAND ai_core_tests
    )
endif()
