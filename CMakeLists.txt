set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_minimum_required(VERSION 3.20)

project(NES_EMULATOR VERSION 0.1
DESCRIPTION "An emulator for the NES"
LANGUAGES C)

file(GLOB_RECURSE nes_src "src/*.c")

add_executable(nes ${nes_src})

find_package(raylib REQUIRED)

target_link_libraries(nes raylib)
target_include_directories(nes PRIVATE include)
target_compile_features(nes PRIVATE c_std_23)
target_compile_options(nes PRIVATE -Wall -Wextra -O2)
