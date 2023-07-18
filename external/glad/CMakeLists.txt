# Follow this template for libraries such as glad or cgltf.
# Put the header files inside include and put C/C++ files inside src.
cmake_minimum_required(VERSION 3.25)
project(Glad)

add_library(glad include/glad/glad.h src/glad.c)
target_include_directories(glad PUBLIC include/)