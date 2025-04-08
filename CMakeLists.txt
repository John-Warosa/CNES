set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_minimum_required(VERSION 3.20)

project(NES_EMULATOR VERSION 0.1
DESCRIPTION "An emulator for the NES"
LANGUAGES C)

file(GLOB_RECURSE cnes_src "src/*.c")

add_executable(cnes ${cnes_src})

find_package(raylib REQUIRED)

target_link_libraries(cnes raylib)
target_include_directories(cnes PRIVATE include)
target_compile_features(cnes PRIVATE c_std_99)
target_compile_options(cnes PRIVATE -std=c99 -Wall -Wextra -O2)
