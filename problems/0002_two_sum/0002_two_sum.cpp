#include <gtest/gtest.h>
#include "0002_two_sum.hpp"

using namespace std;

// ======================================================
// 测试区域 (本地调试与验证)
// ======================================================

TEST(TwoSum, Example1)
{
    Solution sol; // 不需要 namespace，因为每个文件是独立 exe，互不干扰
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> expected = {0, 1};

    EXPECT_EQ(sol.twoSum(nums, target), expected);
}

TEST(TwoSum, Example2)
{
    Solution sol;
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> expected = {1, 2};

    EXPECT_EQ(sol.twoSum(nums, target), expected);
}