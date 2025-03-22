cmake_minimum_required(VERSION 3.20)
project(lecture1803)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow")

add_executable(rational rational.cpp)
add_executable(stack stack.cpp)
add_executable(stack_template stack_template.cpp)
add_executable(stack_template_better stack_template_better.cpp)