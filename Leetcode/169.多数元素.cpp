/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // 排序
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // return nums[n / 2];

        // 摩尔投票法
        int n = nums.size();
        int m = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                m = nums[i];
            }
            if (m == nums[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        return m;
    }
};
// @lc code=end
