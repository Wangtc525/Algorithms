#include <bits/stdc++.h>
using namespace std;
int n, x;
// 0-1背包问题，直接做就行
int main()
{
    cin >> n >> x;
    int sum = 0;
    vector<int> book;
    for (int i = 0; i < n; i++)
    {
        int price;
        cin >> price;
        book.push_back(price);
        sum += price;
    }
    sort(book.begin(), book.end());
    int remain_price = sum - x;

    // 二维数组方法
     int dp[n + 1][remain_price + 1];
     memset(dp, 0, sizeof(dp));
     for (int i = book[0]; i <= remain_price; i++)
     {
         dp[0][i] = book[0];
     }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= remain_price; j++)
        {
            if (j >= book[i])
            {
                int no_select = dp[i - 1][j];
                int select = max(dp[i - 1][j - book[i]] + book[i], book[i]);
                dp[i][j] = max(no_select, select);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << sum - dp[n - 1][remain_price] << endl;

    // 1维数组
    // int dp[remain_price + 1];
    // memset(dp, 0, sizeof(dp));
    // for (int i = book[0]; i <= remain_price; i++)
    // {
    //     dp[i] = book[0];
    // }
    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = remain_price; j >= book[i]; j--)
    //     {
    //         int no_select = dp[j];
    //         int select = max(dp[j - book[i]] + book[i], book[i]);
    //         dp[j] = max(no_select, select);
    //     }
    // }
    // cout << sum - dp[remain_price] << endl;

    return 0;
}