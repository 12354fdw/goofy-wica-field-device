cmake_minimum_required(VERSION 3.22)

project(field-device)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

file(GLOB_RECURSE SOURCES
        "src/*.c"
        "include/*.h"
)

add_executable(field-device ${SOURCES} ${CMAKE_SOURCE_DIR}/startup_stm32c051xx.s)
target_link_libraries(field-device PRIVATE hal-driver)

target_include_directories(field-device PUBLIC include)
target_include_directories(field-device PRIVATE include/fieldDevice)