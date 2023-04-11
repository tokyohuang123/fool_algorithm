cmake_minimum_required( VERSION 3.0)
project( fool_algorithm )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -march=native -O3 -pthread" )
find_package(GTest REQUIRED)#查找gtest包
include_directories(${GTEST_INCLUDE_DIRS}) #包括gtest头文件
include_directories(
        ${PROJECT_SOURCE_DIR}/src/include
)

# 源文件目录
add_subdirectory( ${PROJECT_SOURCE_DIR}/src/ )
add_subdirectory( ${PROJECT_SOURCE_DIR}/test/ )
