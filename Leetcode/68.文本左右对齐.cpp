/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

// @lc code=start
class Solution
{
    // blank 返回长度为 n 的由空格组成的字符串
    string blank(int n)
    {
        return string(n, ' ');
    }

    // join 返回用 sep 拼接 [left, right) 范围内的 words 组成的字符串
    string join(vector<string> &words, int left, int right, string sep)
    {
        string s = words[left];
        for (int i = left + 1; i < right; ++i)
        {
            s += sep + words[i];
        }
        return s;
    }

public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        int right = 0, n = words.size();
        while (true)
        {
            int left = right; // 当前行的第一个单词在 words 的位置
            int sumLen = 0;   // 统计这一行单词长度之和
            // 循环确定当前行可以放多少单词，注意单词之间应至少有一个空格
            while (right < n && sumLen + words[right].length() + right - left <= maxWidth)
            {
                sumLen += words[right++].length();
            }

            // 当前行是最后一行：单词左对齐，且单词之间应只有一个空格，在行末填充剩余空格
            if (right == n)
            {
                string s = join(words, left, n, " ");
                ans.emplace_back(s + blank(maxWidth - s.length()));
                return ans;
            }

            int numWords = right - left;
            int numSpaces = maxWidth - sumLen;

            // 当前行只有一个单词：该单词左对齐，在行末填充剩余空格
            if (numWords == 1)
            {
                ans.emplace_back(words[left] + blank(numSpaces));
                continue;
            }

            // 当前行不只一个单词
            int avgSpaces = numSpaces / (numWords - 1);
            int extraSpaces = numSpaces % (numWords - 1);
            string s1 = join(words, left, left + extraSpaces + 1, blank(avgSpaces + 1)); // 拼接额外加一个空格的单词
            string s2 = join(words, left + extraSpaces + 1, right, blank(avgSpaces));    // 拼接其余单词
            ans.emplace_back(s1 + blank(avgSpaces) + s2);
        }
    }
};
              // @lc code=end
