/*
    FileName: AT_dp_b_Frog_2.cpp
        + randomhash: 2ee61a5f5121f721d767c224
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/21 星期五
    Time: 18:45:31
        + Unix Timestamp(second): 1666349131
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>

#include <cstring>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '

using namespace std;

int n, k;
int h[100010];
int f[100010];

int main()
{
    memset(f, 0x3f, sizeof(f));
    auto cost = [](int x, int y) { return abs(h[x] - h[y]); }; // 传说中的匿名函数
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    f[0] = f[1] = 0; f[2] = f[1] + cost(1, 2);
    for (int i = 1; i <= n; i++)
        for (int j = max(1, i - k); j <= i; j++)
            f[i] = min( f[i], f[j] + cost(i, j) );
    printf("%d\n", f[n]);
    return 0;
}