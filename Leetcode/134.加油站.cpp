/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, minSum = INT_MAX;
        int n = gas.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += gas[i] - cost[i];
            if(sum<minSum){
                start = i + 1;
                minSum = sum;
            }
        }
        if(sum<0){
            return -1;
        }
        return start == n ? 0 : start;
    }
};
// @lc code=end

