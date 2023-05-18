/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            cout << i << endl;
            if (nums[i] > 0)
            {
                break;
            }
            int l = i + 1, r = n - 1;
            while (l < r)
            {

                int data = nums[i] + nums[l] + nums[r];
                if (data > 0)
                {
                    r--;
                }
                else if (data < 0)
                {
                    l++;
                }
                else
                {
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    r--;
                    l++;
                    while (l < r && nums[l] == nums[l - 1])
                    {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r + 1])
                    {
                        r--;
                    }

                    cout << l << " " << r << endl;
                }
            }
            while (i < n - 1 && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
        return res;
    }
};
// @lc code=end
