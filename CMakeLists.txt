cmake_minimum_required(VERSION 3.22)
project(data_managemnt_system C)

set(CMAKE_C_STANDARD 99)

add_executable(data_managemnt_system main.c src/user.c src/headers/user.h src/interface.c src/headers/interface.h src/headers/config.h)
