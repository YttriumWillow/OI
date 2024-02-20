#include <bits/stdc++.h>
#define qwq puts("fzy qwq~");
#define longint long long
#define reg register
#define _read =modread();
using namespace std;
longint a, b, x, y;
const longint mod = 19260817;
inline longint modread()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = ((x << 3) + (x << 1)) % mod + (ch & 15) % mod; ch = getchar(); }
    return x % mod * sgn;
}
void extend_gcd(longint a, longint b, longint& x, longint& y)
{
    if (b == 0)
    {
        x = 1; y = 0;
        return;
    }
    extend_gcd(b, a % b, x, y);
    longint tmp = x;
    x = y;
    y = tmp - (a / b) * y;
}
int main()
{
    a _read; b _read;
    if (b == 0) 
    {
        puts("Angry!");
        return 0;
    }
    extend_gcd(b, mod, x, y);
    x = (x % mod + mod) % mod;
    cout << a * (longint)(x) % mod << endl;
    return 0;
}
