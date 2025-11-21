
#include <vector>
#include <unordered_map>
using namespace std;

// ======================================================
// 题目解答区域 (直接复制 LeetCode 代码)
// ======================================================

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (map.count(complement))
            {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
