cmake_minimum_required(VERSION 3.22)

project(init)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
        "src/*.c"
        "include/*.h"
)

add_library(init STATIC ${SOURCES})
target_link_libraries(init PUBLIC hal-driver)

target_include_directories(init PUBLIC include)
target_include_directories(init PRIVATE include/init)