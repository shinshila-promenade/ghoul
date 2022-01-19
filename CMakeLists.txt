cmake_minimum_required(VERSION 3.0)
project(ghoul_tokio C)

set(CMAKE_C_STANDARD 90)

add_executable(ghoul_tokio ghoul.c tokio.h)
