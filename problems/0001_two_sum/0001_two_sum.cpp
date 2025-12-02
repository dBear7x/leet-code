#include <gtest/gtest.h>
#include "0001_two_sum.hpp"

using namespace std;

TEST(TwoSum, Example1)
{
    Solution sol;
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