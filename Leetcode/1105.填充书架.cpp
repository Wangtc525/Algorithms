/*
 * @lc app=leetcode.cn id=1105 lang=cpp
 *
 * [1105] 填充书架
 */

// @lc code=start
//放书，从后往前，假设当前这一本书包括前面若干本直到j在同一层，那么最高高度就这层书（j->i）的最高高度maxh，然后所有的高度就是dfs(j-1)+maxh
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int bookheight[1001];
    int dfs(vector<vector<int>> &books, int shelfWidth, int i)
    {
        if(i<0){
            return 0;
        }
        if(bookheight[i]!=-1){
            return bookheight[i];
        }
        int res = INT_MAX;
        int maxh = 0;
        int leftwidth = shelfWidth;
        int j;
        for (j = i; j >= 0; j--)
        {
            leftwidth -= books[j][0];
            if(leftwidth<0){
                break;
            }
            maxh = max(maxh, books[j][1]);
            res = min(res, dfs(books, shelfWidth, j - 1) + maxh);
        }
        bookheight[i] = res;
        return res;
    }
    //  int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    // {//记忆化搜索，递归实现
    //     memset(bookheight, -1, sizeof(bookheight));
    //     return dfs(books, shelfWidth, books.size() - 1);
    // }
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth){
        //dp实现
        int dp[1003];
        dp[0] = 0;
        int n = books.size();
        for (int i = 0; i <n; i++)
        {
            dp[i + 1] = INT_MAX;
            int leftwidth = shelfWidth;
            int maxh = 0;
            for (int j = i; j >= 0; j--)
            {
                leftwidth -= books[j][0];
                if(leftwidth<0){
                    break;

                }
                maxh = max(maxh, books[j][1]);
                dp[i + 1] = min(dp[i + 1], dp[j] + maxh);
            }
        }
        return dp[n];
    }
};
// @lc code=end
