/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
        {
            return n;
        }
        int fast = 2, low = 2;

        while (fast < n)
        {
            if (nums[low - 2] != nums[fast])
            {
                nums[low] = nums[fast];
                low++;
            }
            fast++;
        }
        return low;
    }
};
// @lc code=end
