/*
    FileName: P_2196_NOIP_1996_提高组_挖地雷.cpp
        + randomhash: 08b47d
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/15 星期六
    Time: 10:05:37
        + Unix Timestamp(second): 1665799537
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>

#include <cstring>
#include <vector>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '
#define push push_back

using namespace std;

int n, u, v, start, ans, x;
int a[25], f[25], pre[25];
vector<int> g[25];

void path(int x)
{
    if (pre[x] != -1)
        path(pre[x]);
    cout << x << space;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(pre, -1, sizeof(pre));
    cin >> n;
    for (reg int i = 1; i <= n; i++)
        cin >> a[i];
    for (reg int i = 1; i < n; i++)
        for (reg int j = i + 1; j <= n; j++)
        {
            cin >> x;
            if (x) g[j].push(i);
        }
    for (reg int i = 1; i <= n; i++)
    {
        for (auto j : g[i])
            if (f[j] > f[i])
                f[i] = f[j], pre[i] = j;
        f[i] += a[i];
        if (f[i] > ans)
            ans = f[i], start = i;
    }
    path(start);
    cout << endl << ans << endl;
    return 0;
}