/*
    FileName: T_288401_B-莲子的机械动力学.cpp
        + randomhash: 6efb9304a6520474a531e51f
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/11/26 星期六
    Time: 19:03:27
        + Unix Timestamp(second): 1669460607
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>

#include <algorithm>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '

using namespace std;

int n, m;
int a[200010];
int b[200010];
int c[200010];

int main()
{
    scanf("%d%d", &n, &m);
    for (reg int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (reg int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);
    reverse(a + 1, a + n + 1);
    reverse(b + 1, b + m + 1);

    int limit = max(n, m);
    for (reg int i = 1; i <= limit; ++i)
        c[i] = a[i] + b[i];
    for (reg int i = 1; i <= limit + 1; ++i)
    {
        c[i + 1] += c[i] / (i + 1);
        c[i] = c[i] % (i + 1);
    }
    if (c[limit + 1] != 0)
        limit++;
    for (reg int i = limit; i > 0; --i)
        printf("%d ", c[i]);
    return 0;
}