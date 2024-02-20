/*
    FileName: AT_dp_a_A_-_Frog_1.cpp
        + randomhash: dcad6c06b3195633e955b0f2
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/20 星期四
    Time: 20:31:56
        + Unix Timestamp(second): 1666269116
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

int n;
int h[100010], f[100010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (reg int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    f[0] = f[1] = 0; f[2] = abs(h[1] - h[2]);
    for (reg int i = 3; i <= n; i++)
        f[i] = min( f[i - 1] + abs(h[i] - h[i - 1]), f[i - 2] + abs(h[i] - h[i - 2]) );
    cout << f[n] << endl;
    // 好题啊好题（喜
    return 0;
}