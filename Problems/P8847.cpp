/*
    FileName: P_8847_JRKSJ_R_5_1_-_1_A.cpp
        + randomhash: 38a072a87eac917cf404d368
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/11/12 星期六
    Time: 20:13:14
        + Unix Timestamp(second): 1668255194
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

int n, now, tmp;
int cnt[2];

int main()
{
    scanf("%d", &n);
    for (reg int i = 1; i <= n; i++)
    {
        scanf("%d", &now);
        cnt[((now == -1) ? 0 : 1)]++;
    }
    tmp = min(cnt[0], cnt[1]);
    for (reg int i = 1; i <= tmp; i++)
        printf("1 -1 ");
    tmp = n - tmp * 2;
    if (cnt[0] > cnt[1])
        for (reg int i = 1; i <= tmp; i++)
            printf("-1 ");
    else
        for (reg int i = 1; i <= tmp; i++)
            printf("1 ");
    return 0;
}