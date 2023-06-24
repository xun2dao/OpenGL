cmake_minimum_required(VERSION 3.22)
project(OpenGL)


# find package
set(CMAKE_MODULE_PATH "${CMAKE_PROJECT_NAME}/vendor/GLFW/CMake")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(glfw3 REQUIRED)
add_subdirectory("vendor/glad")



add_compile_definitions(OPENGL_DEBUG)
add_compile_definitions(GLFW_INCLUDE_NONE)
add_compile_definitions(CMAKE_BUILD_TYPE "Debug")

add_compile_definitions(PLATFORM_WINDOW_GLFW) # 使用glfw生成窗口

file(GLOB_RECURSE SRC_FILES "src/*.cpp")
message("files : ${SRC_FILES}")
# aux_source_directory("src/" SRC_FILES)

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
