/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // 前缀乘和后缀乘
        int n = nums.size();
        vector<int> prefix(n + 1, 1);
        vector<int> suffix(n + 1, 1);
        for (int i = n - 1; i >= 0; i--)
        {
            suffix[i] = nums[i] * suffix[i + 1];
            // cout << suffix[i] << endl;
        }

        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = nums[i] * prefix[i];
            // cout << prefix[i] << " " << suffix[i+1] << endl;
            nums[i] = prefix[i] * suffix[i + 1];
            // cout << prefix[i] * suffix[i] << endl;
        }
        return nums;
    }
};
// @lc code=end
