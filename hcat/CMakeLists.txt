cmake_minimum_required(VERSION 3.10.0)
project(cat VERSION 0.1.0)


set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wpedantic -Werror")

file(GLOB SOURCES "src/*.c")
add_executable(cat ${SOURCES})
