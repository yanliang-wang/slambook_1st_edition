cmake_minimum_required( VERSION 2.8 )
project( geometry )

# 添加Eigen头文件
set(${CMAKE_BUILD_TYPE} "Release")
include_directories( "/usr/include/eigen3" )

add_executable( eigenGeometry eigenGeometry.cpp )
