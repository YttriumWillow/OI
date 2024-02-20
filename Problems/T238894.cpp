#include <bits/stdc++.h>
#define qwq puts("fzy_qwq\n");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
longint n, m, x, y;
char ch;
struct Node
{
    longint dust = 0, unpasseddays = 0;
} mp[55][55];
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
    y _read; x _read;
    mp[x][y].unpasseddays = -1;
    ch = getchar();
    while (m--)
    {
        ch = getchar();
        //printf("%c", ch);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                { mp[i][j].unpasseddays++; mp[i][j].dust += mp[i][j].unpasseddays; }
        if (ch == 'N')
        {
            y++;
            mp[x][y].unpasseddays = -1;
        }
        if (ch == 'S')
        {
            y--;
            mp[x][y].unpasseddays = -1;
        }
        if (ch == 'W')
        {
            x--;
            mp[x][y].unpasseddays = -1;
        }
        if (ch == 'E')
        {
            x++;
            mp[x][y].unpasseddays = -1;
        }
    }
    //printf("\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", mp[j][n - i + 1].dust);
        printf("\n");
    }
    return 0;
}