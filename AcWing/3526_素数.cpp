#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int n;
int primes[N], cnt;
bool st[N];

void get_primes(int n) // 线性筛
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= n; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

// void get_primes(int n) // 埃氏筛
//{
//   for(int i = 2; i <= n; i ++)
//   {
//       if(!st[i])
//       {
//           primes[cnt ++] = i;
//           for(int j = i + i; j <= n; j += i) st[j] = true;
//       }
//   }
// }

int main()
{
    while (cin >> n)
    {
        cnt = 0;
        memset(st, 0, sizeof st);
        get_primes(n);
        int t = 0;
        for (int i = 0; i < cnt; i++)
        {
            if (primes[i] == n)
                continue;
            if (primes[i] % 10 == 1)
            {
                printf("%d ", primes[i]);
                t++;
            }
        }
        if (!t)
            puts("-1");
        else
            puts("");
    }
    return 0;
}
