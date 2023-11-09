#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;

struct Graph
{
	struct Edge { int v, l, r, nxt; };
	Edge e[M << 1]; int h[N], tot = 1;
	inline void add(int u, int v, int l, int r)
	{ e[++tot] = { v, l, r, h[u] }; h[u] = tot; }
} G;

int n, m, k, t;
int col[N]; bool f;

namespace Sub1
{
inline void dfs(int u, int fa, int c)
{
	if (!f) return;
	col[u] = c;
	for (int i = G.h[u]; i; i = G.e[i].nxt)
	{
		int v = G.e[i].v;
		if (v == fa or t < G.e[i].l or G.e[i].r  <= t) continue;
		if (col[v] == col[u]) { f = 0; break; }
		if (!~col[v]) dfs(v, u, c ^ 1);
	}
}
inline void solve()
{
	for (t = 0; t < k; ++t)
	{
		f = 1;
		fill(col, col + n + 1, -1);
		rep (i, 1, n)
		{
			if (!~col[i]) dfs(i, 0, 0);
			if (!f) break;
		}
		cout << (f ? "Yes" : "No") << endl;
	}
}
}

namespace Sub2
{
inline void dfs(int u, int fa, int c)
{
	if (!f) return;
	col[u] = c;
	for (int i = G.h[u]; i; i = G.e[i].nxt)
	{
		int v = G.e[i].v;
		if (v == fa or t < G.e[i].l or G.e[i].r  <= t) continue;
		if (col[v] == col[u]) { f = 0; break; }
		if (!~col[v]) dfs(v, u, c ^ 1);
	}
}
inline void solve()
{
	f = 1, t = G.e[2].l;
	fill(col, col + n + 1, -1);
	rep (i, 0, G.e[2].r - 1) cout << "Yes" << endl;
	rep (i, 1, n)
	{
		if (!~col[i]) dfs(i, 0, 0);
		if (!f)
		{
			rep (i, G.e[2].l, G.e[2].r - 1) cout << "No" << endl;
			break;
		}
	}
	if (f)
	{
		rep (i, G.e[2].l, G.e[2].r - 1) cout << "Yes" << endl;
	}
	rep (i, G.e[2].r, k - 1) cout << "Yes" << endl;
}
}

int main()
{
	file("yume");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;

	rep (i, 1, m)
	{
		int u, v, l, r;
		cin >> u >> v >> l >> r;
		G.add(u, v, l, r);
		G.add(v, u, l, r);
	}

	if (n <= 5000 and k <= 5000 and m <= 5000) { Sub1::solve(); return 0; }
	Sub2::solve();


	return 0;
}