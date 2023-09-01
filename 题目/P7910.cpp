/*
    FileName: P_7910_CSP-J_2021_插入排序.cpp
        + randomhash: 48d3eb9a377bd54548561229
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/24 星期一
    Time: 18:42:50
        + Unix Timestamp(second): 1666608170
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

int n, Q, opr, x, v;

struct Node
{
    int val, index;
    friend bool operator < (Node _x, Node _y) { return _x.val == _y.val ? _x.index < _y.index : _x.val < _y.val;}
} a[8010];

int mp[8010];

void rebuild()
{
    for (reg int i = 1; i <= n; ++i)
        mp[a[i].index] = i;
}

int main()
{
    scanf("%d%d", &n, &Q);
    for (reg int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i].val);
        a[i].index = i;
    }
    sort(a + 1, a + n + 1);
    rebuild();
    while (Q--)
    {
        scanf("%d%d", &opr, &x);
        if (opr == 1)
        {
            scanf("%d", &v);
            a[mp[x]].val = v;
            for (reg int i = n; i >= 2; --i)
                if (a[i] < a[i - 1])
                    swap(a[i], a[i - 1]);
            // for (reg int i = 2; i <= n; ++i)
            //     if (a[i] < a[i - 1])
            //         swap(a[i], a[i - 1]);
            rebuild();
        }
        else
        {
            printf("%d\n", mp[x]);
        }
    }

    return 0;
}