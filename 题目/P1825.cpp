/*
    FileName: P_1825_USACO_11_OPEN_Corn_Maze_S.cpp
        + randomhash: 9c56575e0e5dd6849313573b
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/22 星期六
    Time: 13:24:31
        + Unix Timestamp(second): 1666416271
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>

#include <queue>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '

using namespace std;

struct Node
{
    int x, y, step;
    Node() {}
    Node(int _x, int _y, int _z) : x(_x), y(_y), step(_z) {}
};

struct Door
{
    int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
} door[26];

char maze[310][310];
bool vis[310][310];
int dx[4] = { 1, 0, -1,  0 };
int dy[4] = { 0, 1,  0, -1 };
int n, m, sx, sy, nx, ny;

void change(char at, int& x, int& y)
{
    if (x == door[at - 'A'].x1 && y == door[at - 'A'].y1)
    {
        x = door[at - 'A'].x2;
        y = door[at - 'A'].y2;
    }
    else
    {
        x = door[at - 'A'].x1;
        y = door[at - 'A'].y1;
    }
}

void makeDoor(char at, int x, int y)
{
    if (door[at - 'A'].x1 == -1)
    {
        door[at - 'A'].x1 = x;
        door[at - 'A'].y1 = y;
    }
    else
    {
        door[at - 'A'].x2 = x;
        door[at - 'A'].y2 = y;
    }
}

void getMaze(int n, int m)
{
    for (reg int i = 0; i <= n + 1; ++i)
        for (reg int j = 0; j <= m + 1; ++j)
            maze[i][j] = '#';
    for (reg int i = 1; i <= n; ++i)
    {
        for (reg int j = 1; j <= m; ++j)
        {
            cin >> maze[i][j];
            if (maze[i][j] == '@')
                sx = i, sy = j;
            if ('A' <= maze[i][j] && maze[i][j] <= 'Z')
                makeDoor(maze[i][j], i, j);
        }
    }
}

void bfs(int sx, int sy)
{
    queue<Node> q;
    q.push(Node(sx, sy, 0));

    while (!q.empty())
    {
        Node now = q.front(); q.pop();
        if (maze[now.x][now.y] == '=') { printf("%d\n", now.step); return; }
        if ('A' <= maze[now.x][now.y] && maze[now.x][now.y] <= 'Z')
            change(maze[now.x][now.y], now.x, now.y);
        for (reg int i = 0; i < 4; ++i)
        {
            nx = now.x + dx[i];
            ny = now.y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && maze[nx][ny] != '#' && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                q.push(Node(nx, ny, now.step + 1));
            }
        }
    }
    return;
}

int main()
{
    scanf("%d%d", &n, &m);
    getMaze(n, m);
    bfs(sx, sy);
    return 0;
}