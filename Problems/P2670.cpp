#include <bits/stdc++.h>
#define qwq puts("fzy qwq ~");
#define longint long long
#define reg register
#define _read =read();
using namespace std;
int n, m;
char ch[114][114];
int get(int x, int y)
{
    int res = 0;
    if (ch[x - 1][y - 1] == '*') res++;
    if (ch[x - 1][y] == '*') res++;
    if (ch[x - 1][y + 1] == '*') res++;
    if (ch[x][y - 1] == '*') res++;
    if (ch[x][y + 1] == '*') res++;
    if (ch[x + 1][y - 1] == '*') res++;
    if (ch[x + 1][y] == '*') res++;
    if (ch[x + 1][y + 1] == '*') res++;
    return res;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> ch[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (ch[i][j] != '*')
                cout << get(i, j);
            else
                cout << '*';
        cout << '\n';
    }
    return 0;
}