/*
    FileName: P_8814_CSP-J_2022_解密_民间数据.cpp
        + randomhash: 7d33f90572ef12858bb14aeb
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/11/06 星期天
    Time: 20:22:48
        + Unix Timestamp(second): 1667737368
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

longint k, n, e, d, p, q, t;
double ans;

int main()
{
    scanf("%lld", &k);
    while (scanf("%lld%lld%lld", &n, &d, &e) != EOF)
    {
        t = n - e * d + 2;
        // p + q = t;
        // p * q = n;
        ans = (-t + sqrt(t * t - 4 * n)) / -2;
        if ((longint)(ans) == ans)
            printf("%lld %lld\n", (longint)(min(ans, t - ans)), (longint)(max(ans, t - ans)));
        else
            printf("NO\n");
    }
    return 0;
}