/*
    FileName: P_3131_USACO_16_JAN_Subsequences_Summing_to_Sevens_S.cpp
        + randomhash: db16f7c28a4d1b5311df865f
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/28 星期五
    Time: 15:42:42
        + Unix Timestamp(second): 1666942962
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
// #define DBG

using namespace std;
const int inf = 0x3fffffff;

int a[50010], sum[50010];
int pre[7], suf[7];
int vp[7];
int n, ans;

#ifdef DBG
void debug()
{
    cerr << "sum[]: ";
    for (reg int i = 1; i <= n; ++i)
        cerr << sum[i] << space;
    cerr << "\npre[]: ";
    for (reg int i = 0; i < 7; ++i)
        cerr << pre[i] << space;
    cerr << "\nsuf[]: ";
    for (reg int i = 0; i < 7; ++i)
        cerr << pre[i] << space;
}
#endif

int main()
{
    scanf("%d", &n);
    for (reg int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        sum[i] = (sum[i - 1] + a[i]) % 7;
        if (!vp[sum[i]]) pre[sum[i]] = i, vp[sum[i]] = 1;
        suf[sum[i]] = i;
    }
    for (reg int i = 0; i < 7; ++i)
        ans = max(ans, suf[i] - pre[i]);
    for (reg int i = 1; i <= n; ++i)
        if (sum[i] == 0)
            ans = max(ans, i);
    printf("%d\n", ans);

#ifdef DBG
    debug();
#endif

    return 0;
}