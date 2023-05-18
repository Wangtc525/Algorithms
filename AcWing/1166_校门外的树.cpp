#include <bits/stdc++.h>
using namespace std;
int tree_l[50001];
int tree_r[50001];
int n;
//括号序列问题，适用于区间更新（比较像单点更新的区间更新），区间查询
int lowbit(int x)
{
    return x & -x;
}
void update(int l, int *tree)
{
    while (l <= n)
    {
        tree[l] += 1;
        l += lowbit(l);
    }
}
int query(int l, int *tree)
{
    int res = 0;
    while (l >= 1)
    {
        res += tree[l];
        l -= lowbit(l);
    }
    return res;
}
int main()
{
    int q;
    cin >> n >> q;
    while (q--)
    {
        int choose;
        int l, r;
        cin >> choose >> l >> r;
        if (choose == 1)
        {
            update(l, tree_l);
            update(r, tree_r);
            // for (int i = 0; i < n; i++)
            // {
            //     cout << tree_l[i] << endl;
            // }
        }
        else
        {
            cout << query(r, tree_l) - query(l - 1, tree_r) << endl;
            // cout << query(r, tree_r) - query(l - 1, tree_l) << endl;
        }
    }
    return 0;
}
// 0 1 2 3 4 5
// 0 1

// 001 010 011 100 101