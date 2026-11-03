cmake_minimum_required(VERSION 3.22)

project(hal-driver)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

file(GLOB_RECURSE SOURCES
        "src/*.c"
        "include/*.h"
)

add_library(hal-driver STATIC ${SOURCES})

target_link_libraries(hal-driver PUBLIC stm32c0xx)

target_include_directories(hal-driver PUBLIC include include/hal)