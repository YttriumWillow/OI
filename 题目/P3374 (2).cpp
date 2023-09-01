/*
    FileName: P_3374_模板_树状数组_1.cpp
        + randomhash: 7047bfb546da82109be494f7
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/12/24 星期六
    Time: 15:12:29
        + Unix Timestamp(second): 1671865949
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

int b[2000010];

int    lowbit(int x) { return x & -x; }
// int lowbit(int k) { return k & -k; }

void add(int x, int v)
{
    for (reg int i = x; i <= n; i += lowbit(i))
        b[i] += v;
}

// void add(int x, int k)
// {
//     while (x <= n)
//     {
//         tree[x] += k;
//         x += lowbit(x);
//     }
// }

int query(int x)
{
    int ans = 0;
    for (reg int i = x; i != 0; i -= lowbit(i))
        ans += b[i];
    return ans;
}

// int sum(int x)
// {
//     int ans = 0;
//     while (x != 0)
//     {
//         ans += tree[x];
//         x -= lowbit(x);
//     }
//     return ans;
// }

int main()
{
    scanf("%d%d", &n, &m);
    for (reg int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        add(i, x);
        // b[i] += x;
        // if (i + lowbit(i) <= n)
        //     b[i + lowbit(i)] += b[i];
    }
    for (reg int i = 1, x, y, z; i <= m; ++i)
    {
        scanf("%d%d%d", &x, &y, &z);
        if (x == 1) add(y, z);
        else printf("%d\n", query(z) - query(y - 1));
    }
    return 0;
}