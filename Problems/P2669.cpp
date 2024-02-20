#include <bits/stdc++.h>
#define qwq puts("fzy qwq ~");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
int n, ans, cnt = 1, tim = 1;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (tim > cnt)
            cnt++, tim = 1;
        tim++;
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}