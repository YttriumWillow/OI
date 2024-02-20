#include <iostream>

#include <queue>
#include <algorithm>

#define int long long
#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

#define Pii pair<int, int>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int inf = 0x3f3f3f3f3f3f;
const int B = N + 1;

int n, m, res;
int d1[N << 1], dx[N << 1];
bool vis[N << 1];

struct Edge { int v, w, nxt; };
Edge e[M << 2]; int h[N], tot;
inline void add(int u, int v, int w)
{ e[++tot] = { v, w, h[u] }; h[u] = tot; }

inline void Dijkstra(int s, int *d)
{
	priority_queue<Pii, vector<Pii>, greater<Pii> > q;
	fill(d, d + n + 1, inf); d[s] = 0; q.push({ 0, s });
	while (!q.empty())
	{
		int u = q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = h[u]; i; i = e[i].nxt)
		{
			int v = e[i].v;
			if (d[v] > d[u] + e[i].w)
			{
				d[v] = d[u] + e[i].w;
				q.push({ d[v], v });
			}
		}
	}
}

namespace Sub1
{
int g[310][310];
int d[310][310];
inline void solve()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			g[i][j] = inf;

	for (int i = 1, u, v, w; i <= m; ++i)
	{
		cin >> u >> v >> w;
		g[u][v] = min(g[u][v], w);
	}

	for (int i = 1; i <= n; ++i) g[i][i] = 0;

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (i != j && k != j)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

	// for (int i = 1; i <= n; ++i)
	// 	for (int j = 1; j <= n; ++j)
	// 		cerr << g[i][j] << " \n"[j == n];

	for (int ed = 2; ed <= n; ++ed)
	{
		res = min(g[1][ed], g[ed][1]);
		for (int i = 1; i <= n; ++i)
		{
			if (i == ed) continue;
			res = min({ res, g[1][i] + g[ed][i], g[1][i] + g[i][ed], g[ed][i] + g[i][1] });
		}
		cout << (res == inf ? -1 : res) << ' ';
	}
}
}

signed main()
{
	// file("coin");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	// if (n <= 200) Sub1::solve(), exit(0);

	for (int i = 1, u, v, w; i <= m; ++i)
	{
		cin >> u >> v >> w;
		add(u, v, w);
		add(v + B, u + B, w);
		add(u, u + B, 0);
		add(v, v + B, 0);
	}

	Dijkstra(1, d1);
	for (int i = 2; i <= n; ++i)
		cout << (d1[i + B] == inf ? -1 : d1[i + B]) << ' ';
	return 0;
}