cmake_minimum_required(VERSION 3.25)
project(cgltf)

add_library(cgltf include/cgltf.h src/cgltf.c)
target_include_directories(cgltf PUBLIC include/)