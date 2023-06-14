cmake_minimum_required(VERSION 3.22)
project(OpenGL)



set(CMAKE_MODULE_PATH "${CMAKE_PROJECT_NAME}/GLFW/CMake")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(glfw3 REQUIRED)
add_subdirectory("vendor/glad")



add_compile_definitions(OPENGL_DEBUG)
add_compile_definitions(GLFW_INCLUDE_NONE)

aux_source_directory("src" SRC_FILES)

add_executable(OpenGL ${SRC_FILES})



if(GLAD_FOUND)
    target_link_libraries(OpenGL glad)
endif()


if(${glfw3_FOUND})
    include_directories("vendor/GLFW/include")
    target_link_libraries(OpenGL glfw)
else(${glfw3_FOUND})
    message(FATAL_ERROR "glfw3 not found")
endif()
     
