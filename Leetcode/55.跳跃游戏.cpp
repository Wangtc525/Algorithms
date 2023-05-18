/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
//每一个位置都更新最远能到达的下标
#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        //贪心做法
        // int max_len = 0;
        // int n = nums.size();
        // for (int i = 0; i < n; i++)
        // {
        //     if (i > max_len)
        //     {
        //         return false;
        //     }
        //     max_len = max(i+nums[i], max_len);

        // }
        // return true;
        //动态规划
        if(nums.size()==1){
            return true;
        }
        if(nums[0]==0){
            return false;
        }
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n-1; i++)
        {
            dp[i] = max(nums[i] + i, dp[i - 1]);
            //从下标i出发，最大能到达nums[i]+i处
            //不从下标i出发，最大能达到dp[i-1]处
            if(dp[i]==i){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

