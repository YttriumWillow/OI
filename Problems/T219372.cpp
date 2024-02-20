#include <bits/stdc++.h>
#define longint long long
#define _read =read()
#define MOD %998244353
using namespace std;
longint n, k, len[110], g;
longint a[200010];
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
inline longint get(longint x)
{

}
int main()
{
    n _read; k _read;
    for (int x = 0; x < n; x++)
    {
        len[x] _read;
        for(int i = 0; i < len[x]; i++)
            a[g++] _read;
    }
    for (int i = 1; i < k; i++)

    // for(int i = 0; i < k; i++)
    //     printf("%lld ", a[i]);
    return 0;
}