#include <bits/stdc++.h>
#define qwq puts("fzy qwq ~");
#define longint long long
#define reg register
#define _read =read();
using namespace std;
int n, m, anss, ansr;
int minn = INT_MAX;
int main()
{
    cin >> n >> m;
    minn = min(n, m);
    ansr = ((1 + n) * (1 + m) * n * m) / 4;
    for (; m >= 1 && n >= 1; m--, n--)
        anss += m * n;
    ansr = ansr - anss;
    cout << anss << ' ' << ansr << endl;
    return 0;
}