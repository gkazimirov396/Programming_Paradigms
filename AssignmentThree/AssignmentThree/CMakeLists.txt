cmake_minimum_required(VERSION 3.28)
project("AssignmentThree")

set(CMAKE_CXX_STANDARD 20)

if (WIN32)
    add_library(caesar SHARED caesar.cpp)
else()
    add_library(caesar SHARED caesar.cpp)
endif()

add_executable("AssignmentThree" main.cpp)

target_link_libraries("AssignmentThree" PRIVATE caesar)