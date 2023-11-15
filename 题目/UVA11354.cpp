#include <iostream>
#include <cstring>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define fir first
#define sec second


using namespace std;

const int N = 3e5 + 10;
const int M = 5e5 + 10;

namespace DSU
{
int fa[N];
inline void init(int len) { rep (i, 1, len + 2) fa[i] = i; }
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y) { fa[x] = y; } // X -> Y
inline void mergeV(int x, int y) { fa[find(x)] = find(y); } // S(x) -> S(y)
};

int n, m, q, cnt;
int w[N], fa[N], siz[N], hsn[N], dep[N], top[N];

struct NaN
{
	int u, v, w;
	friend bool	operator < (const NaN& A, const NaN& B) { return A.w < B.w; }
} E[M];

struct Graph
{
	struct Edge { int v, nxt; };
	Edge e[M << 1]; int h[N], tot = 1;
	inline void add(int u, int v)
	{ e[++tot] = { v, h[u] }; h[u] = tot; }
	inline void clear() { fill(h, h + cnt + 5, 0); tot = 1; }
} T;


inline void dfs1(int u)
{
	hsn[u] = -1; siz[u] = 1;
	dep[u] = dep[fa[u]] + 1;
	for (int i = T.h[u]; i; i = T.e[i].nxt)
	{
		int v = T.e[i].v;
		if (dep[v] or v == fa[u]) continue;
		fa[v] = u; dfs1(v);
		siz[u] += siz[v];
		if (!~hsn[u] or siz[v] > siz[hsn[u]])
			hsn[u] = v;
	}
}

inline void dfs2(int u, int t)
{
	top[u] = t; if (!~hsn[u]) return;
	dfs2(hsn[u], t);
	for (int i = T.h[u]; i; i = T.e[i].nxt)
	{
		int v = T.e[i].v;
		if (v != hsn[u] and v != fa[u])
			dfs2(v, v);
	}
}

inline int LCA(int u, int v)
{
	while (top[u] ^ top[v])
	{
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		u = fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}

inline void ReKruskal()
{
	DSU::init(2 * n);
	cnt = n;

	sort(E + 1, E + m + 1);

	rep (i, 1, m)
	{
		int u = DSU::find(E[i].u);
		int v = DSU::find(E[i].v);
		if (u != v)
		{
			DSU::fa[u] = DSU::fa[v] = ++cnt;
			w[cnt] = E[i].w;
			T.add(cnt, u); T.add(u, cnt);
			T.add(cnt, v); T.add(v, cnt);
		}
	}
}

inline void solve()
{
	rep (i, 1, m)
	{
		int u, v, w; cin >> u >> v >> w;
		E[i] = { u, v, w };
	}

	ReKruskal();

	per (i, cnt, 1) if (!dep[i])
	{
		dep[i] = 1;
		dfs1(i); dfs2(i, i);
	}

	cin >> q;
	rep (i, 1, q)
	{
		int u, v; cin >> u >> v;
		cerr << i << endl;
		cout << w[LCA(u, v)] << endl;
	}

	T.clear();
	fill(w, w + cnt + 5, 0);
	fill(fa, fa + cnt + 5, 0);
	fill(dep, dep + cnt + 5, 0);
}

int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);
	bool f = 0;
	while (cin >> n >> m)
	{
		if (f) cout << endl;
		solve();
		f = 1;
	}
	return 0;
}