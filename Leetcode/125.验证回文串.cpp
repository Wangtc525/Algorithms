/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int n = s.size();
        int l = 0, r = n - 1;
        int l_length = 0, r_length = 0;
        while (l <= r)
        {
            while (l <= n - 1 && !isalnum(s[l]))
            {
                l++;
            }
            while (r >= 0 && !isalnum(s[r]))
            {
                r--;
            }
            // cout << l << " " << r << endl;
            if (l >= r)
            {
                if (l_length == r_length)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

            s[l] = tolower(s[l]);
            s[r] = tolower(s[r]);
            if (s[l] == s[r])
            {
                l_length++;
                r_length++;
            }
            else
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
// @lc code=end
