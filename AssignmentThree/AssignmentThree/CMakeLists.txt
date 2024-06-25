cmake_minimum_required(VERSION 3.28)
project("AssignmentThree")

set(CMAKE_CXX_STANDARD 20)

#add_library(caesar SHARED caesar.cpp)
#add_executable("AssignmentThree" main.cpp)

add_library(caesar STATIC caesar.cpp)
add_executable("AssignmentThree" main_static.cpp)

target_link_libraries("AssignmentThree" PRIVATE caesar)