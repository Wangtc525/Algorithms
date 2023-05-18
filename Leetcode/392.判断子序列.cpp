/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        // 普通
        int s_p = 0;
        int t_p = 0;
        while (s_p < s.size() && t_p < t.size())
        {
            if(s[s_p]==t[t_p]){
                s_p++;
                t_p++;
            }else{
                t_p++;
            }
        }
        cout <<s_p << endl;
        if (s_p == s.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end
