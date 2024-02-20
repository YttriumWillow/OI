#include <bits/stdc++.h>
#define longint long long
#define reg register
#define _read =read()
#define qwq puts("fzy qwq!");
using namespace std;
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
longint n;
struct Node
{
    string str;
    longint id;
} strs[21];
bool cmp(Node _x, Node _y)
{
    if (_x.str.size() == _y.str.size())
        return _x.str > _y.str;
    return _x.str.size() > _y.str.size();
}
int main()
{
    n _read;
    for (int i = 1; i <= n; i++)
    {
        cin >> strs[i].str;
        strs[i].id = i;
    }  
    sort(strs + 1, strs + n + 1, cmp);
    cout << strs[1].id << endl;
    cout << strs[1].str << endl;
    return 0;
}