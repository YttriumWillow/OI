#include <bits/stdc++.h>
#define qwq puts("fzy_qwq\n");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
longint n, m, T;
string str;
longint num[256];
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
int main()
{
    T _read;
    while (T--)
    {
        cin >> str;
        memset(num, 0, sizeof(num));
        bool tmp = false;
        for (int i = 0; i < 17; i++)
        {
            num[str[i]]++;
            if (num[str[i]] >= 4)
                tmp = true;
        }
        if ((num['X'] && num['D']) || tmp)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}