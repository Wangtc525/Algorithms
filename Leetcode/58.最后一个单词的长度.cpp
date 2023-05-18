/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int i = s.size() - 1;
        while(i>=0&&s[i]==' '){
            i--;
        }
        while (i >= 0 && s[i] != ' ')
        {
            i--;
            cnt++;
        }
        return cnt;
    }
};
// @lc code=end

