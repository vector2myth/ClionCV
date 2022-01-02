cmake_minimum_required(VERSION 3.21)
project(ClionCV)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(ClionCV main.cpp)
target_link_libraries(ClionCV ${OpenCV_LIBS})