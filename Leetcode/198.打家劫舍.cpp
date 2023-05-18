/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
// 对于每一户人家，有选与不选两种，选的话，隔壁就不能选了，不选的话，隔壁就可以选。也就是说，选的话，那么就是(dp[i-2]+nums[i]),不选的话，就是dp[i-1]。所以最大值是max(dp[i-2]+nums[i],dp[i-1]);
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // dp实现
        int n = nums.size();
        int dp[n + 2];
        // memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i+2] = max(dp[i+1], dp[i] + nums[i]);
            // dp[i-2] = 1;
        }
        return dp[n + 1];
    }
};
// @lc code=end
