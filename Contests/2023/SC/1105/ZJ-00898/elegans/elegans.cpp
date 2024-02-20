#include <iostream>
#include <tuple>
#include <queue>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 3e5 + 10;
const int M = 3e5 + 10;
const i64 inf = 0x3f3f3f3f3f3f3f3f;

int n, m;
i64 d[N];
bool vis[N];

struct Graph
{
	struct Edge { int v, w, nxt; };
	Edge e[M << 1]; int h[N], tot = 1;
	inline void add(int u, int v, int w)
	{ e[++tot] = { v, w, h[u] }; h[u] = tot; }
} G;

inline void SPFA()
{
	queue<pair<int, int>> q;
	fill(d + 1, d + n + 1, inf);
	q.push({ 1, 1 }); d[1] = 0;
	// fill(vis + 1, vis + n + 1, 0);
	while (!q.empty())
	{
		int u, cnt; tie(u, cnt) = q.front(); q.pop();
		vis[u] = 0;
		for (int i = G.h[u]; i; i = G.e[i].nxt)
		{
			int v = G.e[i].v;
			i64 val = max(d[u], 1ll * cnt * G.e[i].w);
			if (d[v] > val)
			{
				d[v] = val;
				if (!vis[v]) { q.push({ v, cnt + 1 }); vis[v] = 1; }
			}
		}
	}
}

inline void dijkstra() { return; }

int main()
{
	file("elegans");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	rep (i, 1, m)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G.add(u, v, w);
	}

	SPFA();
	cout << d[n] << endl;

	return 0;
}