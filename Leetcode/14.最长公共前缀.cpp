/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int cnt = strs[0].size();
        for (int j = 1; j < strs.size(); j++)
        {
            int i = 0;
            string s1 = strs[j - 1];
            string s2 = strs[j];
            for (; i < cnt && i < s2.size(); i++)
            {
                if (s1[i] != s2[i])
                {
                    break;
                }
            }
            cnt = i;
        }
        return string(strs[0], 0, cnt);
    }
};
// @lc code=end
