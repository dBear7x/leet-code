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

# 3. 核心逻辑：将 `problems` 下的每个子文件夹视为一个题目目录
#    每个题目目录（例如 `problems/0001_two_sum`）中的 .cpp 文件作为该题目的测试源，
#    .hpp 放在同一目录作为实现头文件。

# 搜索顶级子目录
file(GLOB PROBLEM_DIRS RELATIVE ${CMAKE_SOURCE_DIR} "problems/*")

foreach(subdir ${PROBLEM_DIRS})
  if(IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${subdir}")
    # 在子目录下查找 .cpp 源文件（通常是测试文件）
    file(GLOB PROBLEM_SOURCES "${CMAKE_SOURCE_DIR}/${subdir}/*.cpp")

    if(PROBLEM_SOURCES)
      # 使用子目录名作为 target 名称（例如 0001_two_sum）
      get_filename_component(target_name ${subdir} NAME)

      add_executable(${target_name} ${PROBLEM_SOURCES})

      # 包含公共头和题目目录以便找到 .hpp
      target_include_directories(${target_name} PRIVATE
        ${CMAKE_SOURCE_DIR}/common
        ${CMAKE_SOURCE_DIR}/${subdir}
      )

      # 链接 GTest main 来运行测试文件
      target_link_libraries(${target_name} PRIVATE GTest::gtest_main)

      message(STATUS "Found Problem: ${target_name} (from ${subdir})")
    else()
      message(STATUS "Skipping ${subdir}: no .cpp sources found")
    endif()
  endif()
endforeach()