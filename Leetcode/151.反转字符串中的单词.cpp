/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start

// 如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 O(1) 额外空间复杂度的 原地 解法。
// 先逆序，再每个单词换一下顺序即可
class Solution
{
public:
    void swap_str(string &s,int l,int r){
            while (l < r)
            {
                swap(s[l], s[r]);
                l++;
                r--;
            }
    }
    string reverseWords(string s)
    {
        int l = 0, r = s.size() - 1;
        swap_str(s, l, r);
        

        return s;
    }
};
// @lc code=end
