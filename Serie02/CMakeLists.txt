cmake_minimum_required(VERSION 3.13)
project(Serie02 C)

# This is not working correctly in IDE
find_package(Threads)
SET(CMAKE_CXX_FLAGS "-pthread")
# I need to manually compile statistics.c to make it work.

set(CMAKE_C_STANDARD 11)

add_executable(Statistics src/statistics.c)
add_executable(Zombies src/zombies.c)
