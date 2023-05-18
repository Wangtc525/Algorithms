/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution
{
public:
    // int maxProfit(vector<int> &prices)
    // {
    //     int n = prices.size();
    //     vector<int> dp(n + 1, 0);
    //     int min_data = prices[0];
    //     dp[0] = 0;
    //     for (int i = 1; i < n; i++)
    //     {
    //         dp[i] = max(dp[i - 1], prices[i] - min_data);
    //         min_data = min(prices[i], min_data);
    //     }
    //     return dp[n - 1];
    // }
    //贪心
    // int maxProfit(vector<int> &prices)
    // {
    //     int n = prices.size();
    //     int ans = 0;
    //     for (int i = 1; i < n; i++)
    //     {
    //         ans += max(0, prices[i] - prices[i - 1]);
    //     }
    //     return ans;
    // }
    //动态规划
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};
// @lc code=end
