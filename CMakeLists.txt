cmake_minimum_required(VERSION 3.22)
project(OpenGL)



set(CMAKE_MODULE_PATH "${CMAKE_PROJECT_NAME}/GLFW/CMake")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(glfw3 REQUIRED)



file(GLOB "vendor/GLFW/src" SRC)

message("files :${SRC}")

add_executable(OpenGL main.cpp)


if(${glfw3_FOUND})
    include_directories("vendor/GLFW/include")
    target_link_libraries(OpenGL glfw)
else(${glfw3_FOUND})
    message(FATAL_ERROR "glfw3 not found")
endif()
     
