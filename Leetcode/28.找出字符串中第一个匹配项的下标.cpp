/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size();
        int n = needle.size();
        vector<int> next(n + 1, 0);
        next[0] = -1;
        // 计算next数组
        //也可以看作字符串匹配，因为next数组需要从-1开始，这个主要是为了编程方便，就是j=next[j]这一步，而不用写成j=next[j-1]。宗旨就是一直遍历，如果相等就继续往后走，如果不等，则字串索引j指向他的next数值的值。
        int i = 0, j = -1;
        while (i < n - 1)
        {
            if (j == -1 || needle[i] == needle[j])
            {
                i++;
                j++;
                next[i] = j;
            }
            else
            {
                j = next[j];
            }
        }
        i = 0;
        j = 0;
        while (i < m && j < n)
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        if (j == n)
        {
            return i - j;
        }
        else
        {
            return -1;
        }
    }
};
// @lc code=end
