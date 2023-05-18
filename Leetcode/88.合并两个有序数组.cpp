/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
//直接顺序按顺序做下去就行，是否需要新申请一个空间？
//答案是不需要，直接从后往前即可
// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //从前往后
        // int sum = m + n;
        // vector<int> nums3(sum,0);
        // int i = 0,j = 0;
        // int cnt = 0;
        // while (i < m && j < n)
        // {
        //     if(nums1[i]<nums2[j]){
        //         nums3[cnt++] = nums1[i++];
        //     }else{
        //         nums3[cnt++] = nums2[j++];
        //     }
        // }
        // while(i<m){
        //     nums3[cnt++] = nums1[i++];
        // }
        // while(j<n){
        //     nums3[cnt++] = nums2[j++];
        // }
        // nums1.assign(nums3.begin(), nums3.end());

        //从后往前
        int cnt = nums1.size() - 1;
        m -= 1;
        n -= 1;
        while (n >= 0)
        {
            while(m>=0&&nums1[m]>nums2[n]){
                swap(nums1[cnt--] ,nums1[m--]);
            }
            swap(nums1[cnt--] ,nums2[n--]);
        }
    }
};
// @lc code=end

