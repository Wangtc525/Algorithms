/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int res = n;
        int l = -1, r = -1;
        int sum = 0;
        while (l < n && r < n)
        {

            if (sum < target)
            {
                sum += nums[++r];
            }
            else if (sum > target)
            {
                sum -= nums[++l];
            }
            else
            {
                res = min(r - l, res);
                sum += nums[++r];
            }
            // cout << sum << " " << l << " " << r << endl;
            // cout << sum << endl;
        }
        return res;
    }
};
// @lc code=end
