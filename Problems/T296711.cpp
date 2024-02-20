/*
    FileName: T_296711_UOI-R_1_询问.cpp
        + randomhash: a560137d18ec2d10278f166a
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/12/10 星期六
    Time: 17:02:59
        + Unix Timestamp(second): 1670662979
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

int n, m;
int a[1000010];

int main()
{
    scanf("%d%d", &n, &m);
    for (reg int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (reg int i = 1, x, y; i <= m; ++i)
    {
        scanf("%d%d", &x, &y);
        a[x] -= y;
    }
    for (reg int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    return 0;
}