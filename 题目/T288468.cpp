/*
    FileName: T_288468_A-莲子的软件工程学.cpp
        + randomhash: 1e109aee08c35db1d441eac6
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/11/26 星期六
    Time: 18:41:40
        + Unix Timestamp(second): 1669459300
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

longint a, b;

int main()
{
    scanf("%lld%lld", &a, &b);
    if (b > 0)
        printf("%lld\n", abs(a));
    else
        printf("%lld\n", -1 * abs(a));
    return 0;
}