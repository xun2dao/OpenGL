cmake_minimum_required(VERSION 3.22)
project(OpenGL)


file(GLOB "vendor/GLFW/src" SRC)

message("files :${SRC}")

add_executable(OpenGL main.cpp)
