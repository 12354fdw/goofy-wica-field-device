cmake_minimum_required(VERSION 3.22)

project(stm32c0xx)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

file(GLOB_RECURSE SOURCES
        "src/*.c"
        "include/*.h"
)

add_library(stm32c0xx INTERFACE)

target_link_libraries(stm32c0xx INTERFACE cmsis)

target_include_directories(stm32c0xx INTERFACE include)
