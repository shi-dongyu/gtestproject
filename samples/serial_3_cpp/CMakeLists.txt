# demo3 project
cmake_minimum_required (VERSION 3.5)    # CMake 最低版本号要求
project (Demo3)                         # 项目信息

include_directories(${CMAKE_SOURCE_DIR}/math)
include_directories(${CMAKE_SOURCE_DIR})


add_subdirectory(math)                      # 添加 math 子目录
aux_source_directory(. DIR_SRCS)            # 查找当前目录下的所有源文件并将名称保存到 DIR_SRCS 变量

add_library(sum_and_power sumpow.cpp)       # 指定生成目标
target_link_libraries(sum_and_power PRIVATE MathFunctions)   # 添加链接库

add_executable(main main.cpp)    # 指定生成目标

target_link_libraries(main PUBLIC sum_and_power PUBLIC MathFunctions)   # 添加链接库

message("DIR_SRCS = ${DIR_SRCS}")