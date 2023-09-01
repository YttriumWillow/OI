#include <iostream>

#include <cstring>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int INF = 1145141919; 

int x1, y1, x2, y2, nx, ny;
int dx[12] = { -2, -2, -1, -1,  1,  1,  2,  2, -2, -2,  2,  2 };
int dy[12] = {  1, -1,  2, -2,  2, -2,  1, -1,  2, -2,  2, -2 };
bool vis[21][21];
int cnt, ans;
void dfs(int x, int y)
{
    for (int i = 0; i < 12; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx >= 1 && nx <= 20 && ny >= 1 && ny <= 20 && !vis[nx][ny])
        {
            cnt++; vis[nx][ny] = 1;
            if (nx == 1 && ny == 1) ans = min(ans, cnt);
            else dfs(nx, ny);
            cnt--; vis[nx][ny] = 0;
        }
    }
}
int main() {

    cin >> x1 >> y1 >> x2 >> y2;

    ans = INF; cnt = 0;
    dfs(x1, y1); vis[x1][y1] = 1;
    cout << ans << endl; vis[x1][y1] = 0;

    memset(vis, 0, sizeof(vis));
    ans = INF; cnt = 0;
    dfs(x2, y2); vis[x2][y2] = 1;
    cout << ans << endl; vis[x2][y2] = 0;

    return 0;
}