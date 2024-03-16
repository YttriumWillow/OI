#include <bits/stdc++.h>
using namespace std;

int sx, sy, ex, ey;
char mp[1010][1010];
bool vis[1010][1010];
int mov[4][2] = {0, 1, -1, 0, 0, -1, 1, 0};
int dis[1010][1010];
int n, m, k;

struct node {
    int x, y, step;
};
int bfs() {
    queue<node> q;
    vis[sx][sy] = 1;
    q.push(node{sx, sy, 0});
    while (q.size()) {
        node temp = q.front();
        q.pop();
        if (temp.x == ex && temp.y == ey)
            return temp.step;
        for (int i = 0; i < 4; i++) {
            for (int l = 1; l <= k; l++) {
                int xx = temp.x + mov[i][0] * l;
                int yy = temp.y + mov[i][1] * l;
                if (xx < 1 || yy < 1 || xx > n || yy > m || mp[xx][yy] == '#')
                    break;
                if (vis[xx][yy]) {
                    if (dis[xx][yy] == temp.step + 1)
                        continue;
                    else
                        break;
                }
                dis[xx][yy] = temp.step + 1;
                vis[xx][yy] = 1;
                q.push(node{xx, yy, temp.step + 1});
            }
        }
    }
    return -1;
}
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> mp[i] + 1;
    cin >> sx >> sy >> ex >> ey;
    cout << bfs() << endl;

    return 0;
}
