#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>
#include "leetcode_utils.hpp" // 引用公共库，后面会讲

using namespace std;

// ======================================================
// 题目解答区域 (直接复制 LeetCode 代码)
// ======================================================

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.count(complement)) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

// ======================================================
// 测试区域 (本地调试与验证)
// ======================================================

TEST(TwoSum, Example1) {
    Solution sol; // 不需要 namespace，因为每个文件是独立 exe，互不干扰
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> expected = {0, 1};
    
    EXPECT_EQ(sol.twoSum(nums, target), expected);
}

TEST(TwoSum, Example2) {
    Solution sol;
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> expected = {1, 2};
    
    EXPECT_EQ(sol.twoSum(nums, target), expected);
}