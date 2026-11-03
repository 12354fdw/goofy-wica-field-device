cmake_minimum_required(VERSION 3.22)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# PROJECT NAME
set(CMAKE_PROJECT_NAME goofy-wica-field-device)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

enable_language(C ASM)

add_subdirectory(src-drivers)
add_subdirectory(src-field-device)


target_include_directories(hal-driver PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/src-field-device/include/fieldDevice"
)
