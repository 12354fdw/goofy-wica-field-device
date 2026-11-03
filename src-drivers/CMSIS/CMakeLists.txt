cmake_minimum_required(VERSION 3.22)

project(cmsis)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

file(GLOB_RECURSE SOURCES
        "src/*.c"
        "include/*.h"
)

add_library(cmsis INTERFACE)

target_include_directories(cmsis INTERFACE include/)