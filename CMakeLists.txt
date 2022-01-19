cmake_minimum_required(VERSION 3.0)
project(ghoul C)

set(CMAKE_C_STANDARD 90)

add_executable(ghoul_tokio tokio.h ghoul.c)