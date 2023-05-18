/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        int n = s.length(), r = numRows;
        if (r == 1 || r >= n)
        {
            return s;
        }
        string ans;
        int t = r * 2 - 2;
        for (int i = 0; i < r; ++i)
        { // 枚举矩阵的行
            for (int j = 0; j + i < n; j += t)
            {                    // 枚举每个周期的起始下标
                ans += s[j + i]; // 当前周期的第一个字符
                if (0 < i && i < r - 1 && j + t - i < n)
                {
                    ans += s[j + t - i]; // 当前周期的第二个字符
                }
            }
        }
        return ans;
    }
};
              // @lc code=end
