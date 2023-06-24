cmake_minimum_required(VERSION 3.22) 

project(glad)

option(GLAD_FcUND "determine the existence of glad" ON)


aux_source_directory("src" GLAD_SRC)

add_library(glad STATIC  ${GLAD_SRC})
target_include_directories(glad PUBLIC "include") # INTERFACE 和 PUBLIC的区别





