/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {

        // 单调栈思路，单调递减栈，单调栈里面存储每个height的下标。首先入栈0，然后遍历数组，当height[i]大于栈顶元素，直接入栈；当height[i]大于栈顶元素时，意味着存在可以存雨水的地方，那么就将栈顶元素弹出，接下来判断i和此时栈顶元素最低点l，减去弹出的数值，即为高，然后宽度为i-l-1，那么面积就知道了，依次累加。
        if (height.size() == 0)
        {
            return 0;
        }
        stack<int> s;
        s.push(0);
        int sum = 0;
        int n = height.size();
        for (int i = 1; i < n; i++)
        {
            while (!s.empty() && height[i] > height[s.top()])
            {
                int cur = s.top();
                s.pop();
                if (s.empty())
                    break;
                int l = s.top();
                int r = i;
                int h = min(height[l], height[r]) - height[cur];
                sum += h * (r - l -1);
                // cout << i << " " << h << " " << sum << endl;
            }
            s.push(i);
        }
        return sum;
    }
};
// @lc code=end
