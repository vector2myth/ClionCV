cmake_minimum_required(VERSION 3.21)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

# 使用clang和clang++
SET (CMAKE_C_COMPILER             "/usr/bin/clang") # 填写绝对路径
SET (CMAKE_C_FLAGS                "-Wall -std=c99")
SET (CMAKE_C_FLAGS_DEBUG          "-g")
SET (CMAKE_C_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_C_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")

SET (CMAKE_CXX_COMPILER             "/usr/bin/clang++") # 填写绝对路径
SET (CMAKE_CXX_FLAGS                "-Wall")
SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

project(ClionCV)

find_package(OpenCV REQUIRED)
# 添加头文件目录
include_directories(${OpenCV_INCLUDE_DIRS})

# 添加要编译的可执行文件
add_executable(ClionCV main.cpp)
# 添加可执行文件所需要的库
target_link_libraries(ClionCV ${OpenCV_LIBS})