cmake_minimum_required(VERSION 3.6)
project(ResearchC11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11")

set(SOURCE_FILES generics.c)
add_executable(ResearchC11 ${SOURCE_FILES})