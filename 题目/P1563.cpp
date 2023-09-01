#include <bits/stdc++.h>
#define longint long long
#define reg register
#define _read =read()
using namespace std;
longint n, m, now, w, num;
struct Toyman
{
    int way;
    string name;
} man[100001];
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
int main()
{
    n _read; m _read;
    for (int i = 0; i < n; i++)
    {
        man[i].way _read;
        cin >> man[i].name;
    }
    now = 0;
    while (m--)
    {
        w _read; num _read;
        if (w ^ man[now].way)
            now = (now + num) % n;
        else
            now = (n + now - num) % n;
    }
    cout << man[now].name << endl;
    return 0;
}