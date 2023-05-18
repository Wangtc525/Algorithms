/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
// 如果偷nums[0]，那么nums[2]->nums[n-2]，如果不偷nums[0]，那么nums[1]->nums[n-1]。
class Solution
{
public:
    int rob1(vector<int> &nums, int l, int r)
    {
        int n = nums.size();
        int dp[n + 2];
        memset(dp, 0, sizeof(dp));
        // dp[0] = 0;
        // dp[1] = 0;
        for (int i = l; i <= r; i++)
        {
            dp[i + 2] = max(dp[i + 1], dp[i] + nums[i]);
            // dp[i-2] = 1;
        }
        return dp[r + 2];
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        return max(nums[0] + rob1(nums, 2, n - 2), rob1(nums, 1, n - 1));
    }
};
// @lc code=end
