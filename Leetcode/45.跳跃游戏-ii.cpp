/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int jump_1(vector<int> &nums){
        // 对于每一个位置，要么通过前一个位置到达，要么从当前位置重新跳，两者相比的最少跳跃次数。
        int n = nums.size();
        vector<int> cnt(n, 10000);
        cnt[0] = 0;
        for (int i = 0; i < n; i++)
        {
            int step = nums[i];
            // cout << "step " << step << endl;
            for (int j = i + 1; j <= i + step && j < n; j++)
            {
                cnt[j] = min(cnt[i] + 1, cnt[j]);
                // cout << cnt[j] << " ";
            }
            // cout << endl;
        }
        return cnt[n - 1];
    } 
    int jump(vector<int> &nums)
    {
        //方法1，时间复杂度n^2
        return jump_1(nums);

        //方法2,
    }
};
// @lc code=end
