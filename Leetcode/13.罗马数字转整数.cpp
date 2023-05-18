/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution
{
public:
    int number(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }
    int romanToInt(string s)
    {
        stack<char> ns;
        int res = 0;
        for (auto c : s)
        {
            if (!ns.empty() && number(c) > number(ns.top()))
            {
                res += number(c);
                while (!ns.empty())
                {
                    char data = ns.top();
                    res -= number(data);
                    ns.pop();
                }
            }
            else if (!ns.empty() && number(c) <= number(ns.top()))
            {
                char data = ns.top();
                res += number(data);
                ns.pop();
                ns.push(c);
            }
            else
            {
                ns.push(c);
            }
        }
        while (!ns.empty())
        {
            res += number(ns.top());
            ns.pop();
        }
        return res;
    }
};
// @lc code=end
