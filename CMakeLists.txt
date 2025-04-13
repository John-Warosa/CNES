set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_minimum_required(VERSION 3.20)

project(NES_EMULATOR VERSION 0.1
                     DESCRIPTION "An emulator for the NES"
                     LANGUAGES C)

# Find libraries
find_package(raylib REQUIRED)

# === main executable ===

# Get source files
file(GLOB_RECURSE cnes_src "src/*.c")

# Build
add_executable(cnes ${cnes_src})
target_link_libraries(cnes raylib)
target_include_directories(cnes PRIVATE include)
target_compile_features(cnes PRIVATE c_std_99)
target_compile_options(cnes PRIVATE -std=c99 -Wall -Wextra -O2)

# === test suite ===

# Reuse source files without main.c
set(test_src ${cnes_src})
list(REMOVE_ITEM test_src "include/main.c")

# Get test files
file(GLOB_RECURSE test_test "test/*.c")

# Build
add_executable(cnes_test ${test_src} ${test_test})
target_include_directories(cnes_test PRIVATE include test)
target_compile_features(cnes_test PRIVATE c_std_99)
target_compile_options(cnes_test PRIVATE -std=c99 -Wall -Wextra -Werror -O0 -g)
