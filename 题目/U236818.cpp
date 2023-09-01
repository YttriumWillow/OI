#include <bits/stdc++.h>
#define qwq puts("fzy_qwq\n");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
struct Position
{
    longint x = 0, y = 0;
    Position(longint _x, longint _y) : x(_x), y(_y) {};
};
queue<Position> q;
char m[35][35];
bool vis[35][35];
longint n, l, xx, yy, tx, ty, ans;

void bfs(longint x, longint y)
{
    q.push(Position(x, y));
    vis[x][y] = true;
    while (!q.empty())
    {
        xx = q.front().x; yy = q.front().y;
        q.pop();
        for (int ix = -2; ix <= 2; ix++)
        {
            for (int iy = -2; iy <= 2; iy++)// 24 ways
            {
                tx = xx + ix;  ty = yy + iy;
                if ((tx == xx && ty == yy) || tx < 1 || ty < 1 || tx > n || ty > l || m[tx][ty] == '0' || vis[tx][ty] == true)
                    continue;
                vis[tx][ty] = true;
                q.push(Position(tx, ty));
            }
        }
    }
}
int main()
{
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= l; j++)
            cin >> m[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= l; j++)
            if (!vis[i][j] && m[i][j] == '1')
            {
                ans++;

                bfs(i, j);
            }
    printf("%d\n", ans);
    return 0;
}