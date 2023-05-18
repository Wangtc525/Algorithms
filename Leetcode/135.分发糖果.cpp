/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

#include <bits/stdc++.h>
// @lc code=start
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candy(n, 0);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && ratings[i] > ratings[i - 1])
            {
                candy[i] = candy[i - 1] + 1;
            }
            else
            {
                candy[i] = 1;
            }
        }
        int right = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i < n - 1 && ratings[i] > ratings[i + 1])
            {
                right += 1;
            }
            else
            {
                right = 1;
            }
            res += max(right, candy[i]);
        }

        return res;
    }
};
// @lc code=end
