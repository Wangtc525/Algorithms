/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

//双指针，从前往后遍历元素，然后第二个指针从后往前寻找可以替换的元素
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        int j = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i]==val){
                while(j>=i){
                    if(nums[j]!=val){
                        swap(nums[i], nums[j]);
                        break;
                    }
                    j--;
                }
            }
            if(i>j){
                break;
            }
            cnt++;
        }
        return cnt;
    }
};
// @lc code=end

