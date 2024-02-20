#include <bits/stdc++.h>
#define longint long long
#define reg register
#define _read =read()
#define qwq puts("fzy qwq!");
using namespace std;
longint n;
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
    return 0;
}

