/*
    FileName: P_8837_传智杯_3_决赛_商店.cpp
        + randomhash: 18e36d018afec34cf125d4a4
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/11/12 星期六
    Time: 19:45:06
        + Unix Timestamp(second): 1668253506
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

int n, m, now;
int w[114514];
int c[114514];

int main()
{
    scanf("%d%d", &n, &m);
    for (reg int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for (reg int i = 1; i <= m; i++)
        scanf("%d", &c[i]);
    
    sort(w + 1, w + n + 1);
    sort(c + 1, c + m + 1);

    // w, c数组已经排好
    now = 1;
    for (reg int i = 1; i <= n; i++)
    {
        if (w[i] >= c[now])
            now++;
    }
    cout << now - 1 << endl;
    return 0;
}