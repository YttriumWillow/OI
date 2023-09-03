/*
    FileName: P_8588_JROI-_8_雷雨天特别行动科.cpp
        + randomhash: e8a692f3089a2bcbe618ece2
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/23 星期天
    Time: 14:55:24
        + Unix Timestamp(second): 1666508124
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

longint x, k;
int main()
{
    scanf("%lld%lld", &x, &k);
    while (x != 1 && k > 0)
    {
        ++x;
        if (x % 3 == 0)
            x /= 3;
        --k;
    }
    for (int i = 1; i <= n; ++i)
    printf("%lld\n", x + (k & 1));
    return 0;
}
