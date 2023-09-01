#include <bits/stdc++.h>
#define longint long long
#define reg register
#define _read =read()
using namespace std;
struct DpNode
{
    longint length = 0;
    vector<longint> now;
} f[510];
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
longint n1, n2, a[510], b[510];
int main()
{
    n1 _read;
    for (int i = 1; i <= n1; i++)
        a[i] _read;
    n2 _read;
    for (int i = 1; i <= n2; i++)
        b[i] _read;
    
    for (int i = 1; i <= n1; i++)
    {
        DpNode maxn;
        for (int j = 1; j <= n2; j++)
        {
            if (a[i] > b[j] && f[j].length > maxn.length)
                maxn = f[j];
            if (a[i] == b[j])
            {
                f[j].length = maxn.length + 1;
                f[j].now = maxn.now;
                f[j].now.push_back(a[i]);
            }
        }
    }
    DpNode ans = f[1];
    for (int i = 2; i <= n1; i++)
    {
        if (f[i].length > ans.length)
            ans = f[i];
    }
    cout << ans.length << endl;
    for (int i = 0; i < ans.length; i++)
        cout << ans.now[i] << ' ';
    cout << endl;
    return 0;
}


// // chang (longit C)
// {
//     cha r
// }