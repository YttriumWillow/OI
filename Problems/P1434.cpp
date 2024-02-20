#include <iostream>
#include <queue>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 110;

int n, m, res;
int h[N][N], f[N][N];
int dx[4] = { -1,  0, 1, 0 };
int dy[4] = {  0, -1, 0, 1 };

struct P
{
	int x, y;
	friend bool operator < (const P& a, const P&b)
	{ return h[a.x][a.y] < h[b.x][b.y]; }
};

priority_queue<P> q;

#define chk(x, y) ((x >= 1 && x <= n && y >= 1 && y <= m))

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> h[i][j];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			q.push({ i, j });

	while (!q.empty())
	{
		P u = q.top(); q.pop();
		int x = u.x, y = u.y;
		for (int i = 0; i < 4; ++i)
		{
			int px = x + dx[i];
			int py = y + dy[i];
			if (chk(px, py) && h[px][py] > h[x][y])
				f[x][y] = max(f[x][y], f[px][py] + 1);
		}
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			res = max(res, f[i][j]);

	cout << res + 1 << endl;
	return 0;
}