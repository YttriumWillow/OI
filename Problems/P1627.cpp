#include <bits/stdc++.h>
#define qwq puts("fzy qwq~");
#define longint long long
#define ltolpair longint, longint
#define reg register
#define _read =read()
using namespace std;
longint n, b, a[100010], ans;
longint pos, l, r;
map<ltolpair> mp;
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') { sgn = -1; } ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
int main()
{
    n _read; b _read;
    for (int i = 1; i <= n; i++)
    {
        a[i] _read;
        if (a[i] == b)
            pos = i;
    }
    // fzy看完tj来口胡一下
    // mp是干嘛的？- mp记录对应关系
    /*
        7 4
        begin       pos         end
        5   7   2   4   3   1   6
        1   0   -1  ?   -1  -2  -1
        mp[-2] = 1, mp[-1] = 3;
    */
    for (int i = pos; i <= n; i++)
    {
        if (a[i] > b) r++;
        if (a[i] < b) r--;
        mp[r]++;
    }
    for (int i = pos; i >= 1; i--)
    {
        if (a[i] > b) l++;
        if (a[i] < b) l--;
        ans += mp[0 - l];
        // printf("mp[%lld]=%lld, ", 0 - l, mp[0 - l]);
    }
    printf("%lld\n", ans);
    return 0;
}