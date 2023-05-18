/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();
        int l = 0, r = n - 1;
        int res = 0;
        while (l <= r)
        {
            int h = min(height[r], height[l]);
            int water = h * (r - l);
            res = max(res, water);
            if(height[r]>height[l]){
                l++;
            }else{
                r--;
            }
        }
        return res;
    }
};
// @lc code=end

