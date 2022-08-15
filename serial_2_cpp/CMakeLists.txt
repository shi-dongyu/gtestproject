cmake_minimum_required (VERSION 3.5)    # CMake 最低版本号要求
project (Demo3)                         # 项目信息
include_directories(${CMAKE_SOURCE_DIR}/math)


add_subdirectory(math)              # 添加 math 子目录

aux_source_directory(. DIR_SRCS)    # 查找当前目录下的所有源文件并将名称保存到 DIR_SRCS 变量
add_executable(Demo ${DIR_SRCS})    # 指定生成目标
target_link_libraries(Demo PRIVATE MathFunctions)   # 添加链接库

message("DIR_SRCS = ${DIR_SRCS}")
