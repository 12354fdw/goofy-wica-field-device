cmake_minimum_required(VERSION 3.22)

project(drivers)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

add_subdirectory(CMSIS)
add_subdirectory(STM32C0xx)
add_subdirectory(STM32C0xx_HAL_Driver)