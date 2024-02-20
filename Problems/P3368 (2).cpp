/*
    FileName: P_3368_模板_树状数组_2.cpp
        + randomhash: a3b6a1585dfd4bb9b1f3869b
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2023/01/07 星期六
    Time: 13:12:02
        + Unix Timestamp(second): 1673068322
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

const int SIZE = 500010;

int n, m, last;

struct BIT
{
    int len;
    BIT() {}
    BIT(int n) { len = n; }
    longint val[SIZE] = { 0 };
    longint dif[SIZE] = { 0 };
    longint lowbit(int x) { return x & -x; }

    void add(int x, longint v)
    {
        for (reg int i = x; i <= len; i += lowbit(i))
            dif[i] += v;
    }
    void addrange(int x, int y, longint v)
    {
        add(x, v);
        add(y + 1, -v);
    }
    longint query(int x)
    {
        longint ans = 0;
        for (reg int i = x; i > 0; i -= lowbit(i))
            ans += dif[i];
        return ans;
    }
};

int main()
{
    scanf("%d%d", &n, &m);
    BIT tree(n);
    for (reg int i = 1; i <= n; ++i)
    {
        scanf("%lld", &tree.val[i]);
        // tree.dif[i] = tree.dif[i] - tree.dif[i - 1];
    }
    for (reg int i = 1; i <= n; ++i)
    {
        tree.addrange(i, i, tree.val[i]);
    }
    for (reg int i = 1, p, x, y; i <= m; ++i)
    {
        scanf("%d", &p);
        if (p == 1)
        {
            longint k;
            scanf("%d%d%lld", &x, &y, &k);
            tree.addrange(x, y, k);
        }
        else
        {
            scanf("%d", &y);
            printf("%lld\n", tree.query(y));
        }
    }
    return 0;
}