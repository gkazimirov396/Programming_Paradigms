cmake_minimum_required(VERSION 3.28)
project("AssignmentFour")

set(CMAKE_CXX_STANDARD 20)

add_library(caesar SHARED caesar.cpp "text.h" "command_line_interface.h")
#add_executable("AssignmentFour" main.cpp)

#target_link_libraries("AssignmentFour" PRIVATE caesar)
