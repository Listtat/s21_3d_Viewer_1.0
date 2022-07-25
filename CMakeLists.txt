cmake_minimum_required(VERSION 3.21)
project(C8 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(C8
        s21_3D_Viewer_1.0.c
        s21_3D_Viewer_1.0.h
        cub.obj)
