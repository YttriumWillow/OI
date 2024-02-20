/*
    FileName: P_1731_NOI_1999_生日蛋糕.cpp
        + randomhash: 65bf11ea8546471cbb437e57
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/12/07 星期三
    Time: 19:24:25
        + Unix Timestamp(second): 1670412265
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>
#include <cmath>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '

using namespace std;
const int inf = 0x7fffffff;

int r[30], h[30];
int minn = inf;
int n, m;

void dfs(int x, int now, int k, int p)
{
    if (now < 0 || x > m + 1 || k >= minn)
        return;
    if (now == 0 && x == m + 1)
    {
        k += r[1] * r[1];
        if (k < minn)
            minn = k;
        return;
    }
    if (k + p + r[1] * r[1] > minn || now - r[x - 1] * r[x - 1] * h[x - 1] * p > 0)
        return;
    for (int i = r[x - 1] - 1; i >= p; --i)
        for (int j = h[x - 1] - 1; j >= p; --j)
            if (now - i * i * j >= 0 && x <= m)
            {
                r[x] = i; h[x] = j;
                dfs(x + 1, now - i * i * j, k + 2 * i * j, p - 1);
                r[x] = 0; h[x] = 0;
            }
}
int main()
{
    scanf("%d%d", &n, &m);
    r[0] = sqrt(n); h[0] = sqrt(n);
    dfs(1, n, 0, m);
    if (minn == inf)
        printf("%d", 0);
    else
        printf("%d", minn);
    return 0;
}