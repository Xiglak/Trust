cmake_minimum_required(VERSION 3.29)
project(Trust C)

set(CMAKE_C_STANDARD 11)

add_executable(Trust main.c
        Data_struct.c
        key_dict.h
        key_dict.c
        key_dict.h)
