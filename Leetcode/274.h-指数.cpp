/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end(), [](int x, int y)
             { return x > y; });
        int n = citations.size();
        citations.push_back(0);
        int max_h = 0;
        for (int i = 0; i < n; i++)
        {
            int h1 = citations[i];
            int h2 = citations[i + 1];
            if (h1 >= (i + 1) && (i + 1) >= h2)
            {
                max_h = max(max_h, i + 1);
            }
        }
        return max_h;
    }
};
// @lc code=end
