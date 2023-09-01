/*
    FileName: P_1387_最大正方形.cpp
        + randomhash: 672cbfcaea49a1aa459c0998
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/28 星期五
    Time: 16:35:00
        + Unix Timestamp(second): 1666946100
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '
// #define DBG

using namespace std;

int n, m, x, ans;
int sum[110][110];

#ifdef DBG
void dbg()
{
    for (reg int i = 1; i <= n; ++i)
    {
        for (reg int j = 1; j <= m; ++j)
            printf("%d ", sum[i][j]);
        printf("\n");
    }
}
#endif

int calc(int i, int j, int ii, int jj)
{
    return sum[i][j] + sum[ii][jj] - sum[i][jj] - sum[ii][j];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= m; ++j)
            scanf("%d", &x), sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + x;
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= m; ++j)
            for (reg int k = 1; k <= min(i, j); ++k)
                if (calc(i, j, i - k, j - k) == k * k)
                    ans = max(ans, k); //, printf("log->pos:%d,%d k:%d\n", i, j, k);
#ifdef DBG
    dbg();
#endif
    printf("%d\n", ans);
    return 0;
}