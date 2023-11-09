#include <iostream>
#include <queue>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e5 + 10;
const int M = 1e5 + 10;
const int inf = 0x3f3f3f3f;

int n, m, res = -1;
int dg[N], d[N];

struct Graph
{
	struct Edge { int v, nxt; };
	Edge e[M << 1]; int h[N], tot = 1;
	inline void add(int u, int v)
	{ e[++tot] = { v, h[u] }; h[u] = tot; }
} G;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	rep (i, 1, m)
	{
		int u, v; cin >> u >> v;
		G.add(u, v); ++dg[v];
	}

	queue<int> q;

	rep (i, 1, n) if (!dg[i]) q.push(i);

	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int i = G.h[u]; i; i = G.e[i].nxt)
		{
			int v = G.e[i].v;
			d[v] = max(d[v], d[u] + 1);
			if (!--dg[v]) q.push(v);
		}
	}

	rep (i, 1, n) res = max(res, d[i]);

	cout << res << endl;

	return 0;
}