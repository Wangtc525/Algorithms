/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// //要么偷当前的，要么隔一个偷一个
// class Solution
// {
// public:
//     int dfs(TreeNode *node, int flag)
//     {
//         int value = 0;
//         if (node == NULL)
//         {
//             return 0;
//         }
//         if(flag==0){
//             return dfs(node->left, 1) + dfs(node->right, 1);
//         }

//         value = max(node->val + dfs(node->left, 0) + dfs(node->right, 0), dfs(node->left, 1) + dfs(node->right, 1));
//         return value;
//     }
//     int rob(TreeNode *root)
//     {
//         return dfs(root, 1);
//     }
// };

// 树形dp
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 返回长度为2的数组，0不偷，1偷
    vector<int> robTree(TreeNode *cur)
    {
        if (cur == NULL)
            return vector<int>{0, 0};
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // 偷cur，那就不能偷左右节点
        int val1 = cur->val + left[0] + right[0];
        // 不偷cur，那么可以偷也可以不偷左右节点，取左右节点的更大值
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val2, val1};
    }
    int rob(TreeNode *root)
    {
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }
};
// @lc code=end
