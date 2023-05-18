/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
//本题的思考：子结构定义为每天的利润，记录一个最小值，然后遍历数组，同时判断每天的利润
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> dp(n + 1, 0);
        int min_data = prices[0];
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i - 1], prices[i] - min_data);
            //当天的利润等于前一天的利润与当前的股票价格减去最低买入价的最大值
            // cout << dp[i] << min_data << endl;
            min_data = min(prices[i], min_data);
        }
        return dp[n - 1];
    }
};
// @lc code=end
