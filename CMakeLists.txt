cmake_minimum_required(VERSION 3.14)

project(LeetCode-Cpp CXX)

set(CMAKE_CXX_STANDARD 17)

# 1. 引入 GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 2. 包含 common 目录，方便引用 TreeNode/ListNode 定义
include_directories(${CMAKE_SOURCE_DIR}/common)

# 3. 核心逻辑：扫描 src 文件夹
file(GLOB PROBLEM_SOURCES "src/*.cpp")

foreach(source_file ${PROBLEM_SOURCES})
    # 获取文件名作为 target 名字 (例如 0001_two_sum)
    get_filename_component(target_name ${source_file} NAME_WE)

    # 为该文件创建独立的可执行程序
    add_executable(${target_name} ${source_file})

    # 链接 gtest_main (它包含了 main 函数，不需要你手写 main)
    target_link_libraries(${target_name} GTest::gtest_main)
    
    # (可选) 如果需要多线程，通常加上这个
    target_link_libraries(${target_name} Threads::Threads)
    
    message(STATUS "Found Problem: ${target_name}")
endforeach()