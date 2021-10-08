cmake_minimum_required(VERSION 3.0.0)
project(hcat VERSION 0.1.0)

set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wpedantic")

add_executable(hcat "hcat.c")
