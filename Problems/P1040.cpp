// Problem:	P1040 [NOIP2003 提高组] 加分二叉树
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/P1040
// Memory Limit:	128 MB
// Time Limit:	1000 ms
// Created Time:	2023-03-11 19:29:35

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n;
int a[35], rt[35][35];
i64 dp[35][35];

inline void checktree(i64 l, i64 r)
{
    if (l > r) return;
    cout << rt[l][r] << ' ';
    checktree(l, rt[l][r] - 1);
    checktree(rt[l][r] + 1, r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (reg i64 i = 1; i <= n; ++i)
        cin >> a[i];
    for (reg i64 i = 1; i <= n; ++i)
    {
        dp[i][i] = a[i];
        rt[i][i] = i;
    }
    for (reg int len = 1; len <= n; ++len)
    {
        for (reg int l = 1; l <= n - len; ++l)
        {
            int r = l + len;
            dp[l][r] = dp[l + 1][r] + dp[l][l]; // with leftson tree empty
            rt[l][r] = l;						// faq initalize
            
            for (reg int x = l + 1; x <= r - 1; ++x)
                if (dp[l][r] < dp[l][x - 1] * dp[x + 1][r] + dp[x][x])
                {
                    dp[l][r] = dp[l][x - 1] * dp[x + 1][r] + dp[x][x];
                    rt[l][r] = x;
                }
        }
    }
    cout << dp[1][n] << endl;
	checktree(1, n);
    return 0;
}