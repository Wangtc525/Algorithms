/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    //较low的快慢指针法
    // int removeDuplicates(vector<int> &nums)
    // {
    //     if (nums.size() <= 1)
    //     {
    //         return nums.size();
    //     }
    //     int i = 0, j = 0;
    //     int n = nums.size();
    //     int cnt = 0;
    //     while (i < n)
    //     {
    //         j = i + 1;
    //         while (j < n && nums[i] >=nums[j])
    //         {
    //             j++;
    //         }
    //         if (j == n)
    //         {
    //             break;
    //         }
    //         nums[i + 1] = nums[j];
    //         i++;
    //     }
    //     return i+1;
    // }

    //优化的快慢指针法
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return n;
        }
        int fast = 1, low = 1;

        while (fast < n)
        {
            if (nums[low - 1] != nums[fast])
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
