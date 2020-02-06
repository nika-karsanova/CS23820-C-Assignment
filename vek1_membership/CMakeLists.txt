cmake_minimum_required(VERSION 3.14)
project(CS23820_Assignment C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_executable(CS23820_Assignment main.c membership.c membership.h)