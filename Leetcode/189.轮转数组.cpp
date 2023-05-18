/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    // 原地方法

    void reverse(vector<int> &nums, int begin, int end)
    {
        while(begin<end){
            swap(nums[begin], nums[end]);
            begin++;
            end--;
        }
    }
    void rotate(vector<int> &nums, int k)
    {

        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};
// @lc code=end
