/*
    FileName: P_5017_NOIP_2018_普及组_摆渡车.cpp
        + randomhash: c018dd2637162653db1f7593
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/17 星期一
    Time: 21:23:18
        + Unix Timestamp(second): 1666012998
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

const int maxT = 4000105;

int n, m, t, ti, ans = 1e9, cnt[maxT], sum[maxT], f[maxT];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &ti);
        t = max(t, ti);
    }
    cnt[ti]++; sum[ti] += ti;
    for (int i = 1; i < t + m; i++)
    {
        cnt[i] += cnt[i - 1];
        sum[i] += sum[i - 1];
    }
    for (int i = 0; i < t + m; i++)
    {
        f[i] = cnt[i] * i - sum[i];
        for (int j = 0; j <= i - m; j++)
            f[i] = min(f[i], f[j] + (cnt[i] - cnt[j]) * i - (sum[i] - sum[j]));
    }
    for (int i = t; i < t + m; i++)
        ans = min(ans, f[i]);
    printf("%d\n", ans);
    return 0;
}
