/*
    FileName: U_252604_探索未知.cpp
        + randomhash: f4b078
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/16 星期天
    Time: 10:19:34
        + Unix Timestamp(second): 1665886774
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

longint gcd(longint a, longint b) { return b == 0 ? a : gcd(b, a % b); }
// inline longint gcd(longint a, longint b) { while (b ^= a ^= b ^= a %= b); return a; }
inline longint lcm(longint a, longint b) { return a * b / gcd(a, b); }

longint n, m, a, b, opr;

struct Frac
{
    longint a, b;
    bool flag;
    Frac() {}
    Frac(longint _a, longint _b) : a(_a), b(_b) {}
    Frac operator + (Frac _x)
    {
        longint tmp = lcm(b, _x.b);
        longint newa = (tmp / b) * a + (tmp / _x.b) * _x.a;
        return Frac(newa, tmp);
    }
    Frac operator - (Frac _x)
    {
        longint tmp = lcm(b, _x.b);
        longint newa = (tmp / b) * a - (tmp / _x.b) * _x.a;
        return Frac(newa, tmp);
    }
    void print()
    {
        if (a == 0) cout << 0 << endl;
        else
        {
            longint tmp = gcd(a, b);
            longint na = a / tmp, nb = b / tmp;
            if (na % nb == 0)
                cout << na / nb;
            else if (nb < 0)
                cout << na / -1 << '/' << nb / -1 << endl;
            else
                cout << na << '/' << nb << endl;
        }
        return;
    }
} ans;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n; ans = Frac(0, 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> opr;
        if (opr == 1)
            ans = ans + Frac(a, b);
        else
            ans = ans - Frac(a, b);
    }
    ans.print();
    return 0;
}