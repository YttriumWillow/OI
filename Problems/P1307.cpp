#include <bits/stdc++.h>
#define longint long long
#define reg register
#define _read =read()
using namespace std;
longint n, ans;
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
int main()
{
    n _read;
    while(n)
    {
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    cout << ans << endl;
    return 0;
}