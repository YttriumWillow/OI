/*
    FileName: P_1118_USACO_06_FEB_Backward_Digit_Sums_G_S.cpp
        + randomhash: 9467e8b62349dec4ae88cfd4
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/28 星期五
    Time: 20:49:50
        + Unix Timestamp(second): 1666961390
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '

using namespace std;

int n, s;
int ans[21], c[21];
bool vis[21];

bool dfs(int i, int p, int now)
{
    if (now > s) return false;
    if (i == n)
    {
        if (now == s)
        {
            ans[i] = p;
            return true;
        }
        else return false;
    }
    vis[p] = true;
    for (reg int j = 1; j <= n; ++j)
    {
        if (!vis[j] && dfs(i + 1, j, now + c[i] * j))
        {
            ans[i] = p;
            return true;
        }
    }
    vis[p] = false;
    return false;
}

int main()
{
    scanf("%d%d", &n, &s); c[0] = 1;
    for (reg int i = 1; i <= n; ++i)
        c[i] = (n - i) * c[i - 1] / i;
    if (dfs(0, 0, 0))
        for (reg int i = 1; i <= n; ++i)
            printf("%d ", ans[i]);
    return 0;
}