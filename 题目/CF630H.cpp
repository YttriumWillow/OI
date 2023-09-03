#include <bits/stdc++.h>
#define qwq puts("fzy qwq~");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') { sgn = -1; } ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
longint n, m, ans = 1;
int main()
{
    cin >> n;
    for (int i = 0; i < 5; i++)
    {
        ans *= (n - i) * (n - i);
        ans /= (i + 1);
    }
    cout << ans << endl;
    return 0;
}