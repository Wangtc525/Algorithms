#include <bits/stdc++.h>
int dp[1001];
int N, V;
int v[1001];
int price[1001];
using namespace std;
int main()
{
    int N, V;
    cin >> N >> V;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i] >> price[i];
    }
    // for (int i = v[0]; i <= V; i++)
    // {
    //     dp[i] = (i / v[0]) * price[0];
    // }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            int no_select = dp[j];
            int select = j >= v[i] ? max(dp[j - v[i]] + price[i], price[i]) : 0;
            dp[j] = max(no_select, select);
        }
    }
    cout << dp[V] << endl;
}