/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
// 先获取小于n的所有完全平方数，打个表，然后直接dp实现
//  @lc code=start
using namespace std;
#include <vector>
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> arr;
        int i = 1;

        while (i * i <= n)
        {
            arr.push_back(i * i);
            i++;
        }

        int l = arr.size();
        int dp[l][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            int k = i / arr[0];
            if (k * arr[0] == i)
            {
                dp[0][i] = i / arr[0];
            }
        }
        // dp数组里面存储的是每个完全平方数累加起来等于n的最少数量，如dp[0][i]存储的是第一个完全平方数加起来等于n,dp[1][i]存储的是前两个完全平方数加起来等于n的最少组合。每次遍历这个二维数组即可。
        for (int i = 1; i < l; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int no_select = dp[i - 1][j]; // 不选的话直接等于前一个数在该位置的数量
                int k = j / arr[i];
                int select = dp[i - 1][j]; // 如果选择，先设置为前一个数的数量
                while (k > 0)
                {
                    int nnn = dp[i - 1][j - k * arr[i]] + k;
                    if (nnn < select)
                    {
                        select = nnn;
                        break;
                    }
                    // select = min(dp[i - 1][j - k * arr[i]] + k, select);
                    k--;
                }
                dp[i][j] = min(select, no_select);
            }
        }
        return dp[l - 1][n];
    }
};
// @lc code=end
