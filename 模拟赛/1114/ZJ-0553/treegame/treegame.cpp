#include <iostream>
#include <vector>

#define i64 long long
#define endl '\n'
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e6 + 10;
const int M = 1e6 + 10;

int n, k, dg[N];
bool f[N], col[N];

struct Graph
{
	struct Edge { int v, nxt; };
	Edge e[M << 1]; int h[N], tot = 1;
	inline void add(int u, int v)
	{ e[++tot] = { v, h[u] }; h[u] = tot; }
} T;

inline void coloring(int u, int fa, int c)
{
	col[u] = c;
	for (int i = T.h[u]; i; i = T.e[i].nxt)
	{
		int v = T.e[i].v;
		if (v == fa) continue;
		coloring(v, u, c ^ 1);
	}
}

inline void solve1()
{
	// coloring(1, 0, 0);

	rep (u, 1, n) if (dg[u] == 1)
	{
		for (int i = T.h[u]; i; i = T.e[i].nxt)
		{
			int v = T.e[i].v;
			f[v] = 1;
		}
	}

	rep (i, 1, n) if (f[i]) cout << i << ' ';

}

inline void solve2()
{
	
}

int main()
{
	file("treegame");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	rep (i, 2, n)
	{
		int u, v; cin >> u >> v;
		T.add(u, v); T.add(v, u);
		++dg[u], ++dg[v];
	}

	if (k == 1) solve1();
	if (k == 2) solve2();

	return 0;
}