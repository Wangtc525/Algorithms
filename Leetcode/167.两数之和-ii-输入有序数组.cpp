/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int> res;
        int n = numbers.size();
        int l = 0, r = n - 1;
        while(l<=r){
            if(numbers[l]+numbers[r]>target){
                r--;
            }
            else if (numbers[l] + numbers[r] < target)
            {
                l++;
            }else{
                res.push_back(l+1);
                res.push_back(r+1);
                return res;
            }
        }
        return res;
    }
};
// @lc code=end

