#include <iostream>
#include <algorithm>
#include <vector>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define pb push_back

using namespace std;

const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, m, q, cnt, siz[N], ff[N];

struct Edge { int v, nxt; };
Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v)
{ e[++tot] = { v, h[u] }; h[u] = tot; }

// struct SubTree { int fa, siz; } sub[M];

namespace LinkCutLCA
{
int hson[N], sizz[N];
int dep[N], fa[N];
int top[N];
inline void init(int u)
{
	hson[u] = -1; sizz[u] = 1;
	dep[u] = dep[fa[u]] + 1;
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (!dep[v])
		{
			if (v == fa[u]) continue;
			fa[v] = u; init(v);
			sizz[u] += sizz[v];
			if (!~hson[u] || sizz[v] > sizz[hson[u]])
				hson[u] = v;
		}
	}
}

inline void cut(int u, int tp)
{
	top[u] = tp; ++cnt;
	if (!~hson[u]) return;
	cut(hson[u], tp);
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (v != hson[u] && v != fa[u])
			cut(v, v);
	}
}

inline int LCA(int u, int v)
{
	while (top[u] != top[v])
		(dep[top[u]] > dep[top[v]]) ? u = fa[top[u]] : v = fa[top[v]];
	return dep[u] < dep[v] ? u : v;
}
} using namespace LinkCutLCA;

inline void prefix(int u)
{
	siz[u] = 1;
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		prefix(v);
		siz[u] += siz[v];
	}
}

namespace _30pts
{
int a, b;
vector<int> sub[N];
inline void fix(int u)
{
	sub[a].pb(u);
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		fix(v);
	}
}
inline int id(int a, int x) { return (*lower_bound(sub[a].begin(), sub[a].end(), x) - *sub[a].begin()); }
inline void insert(int u)
{
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		// cerr << "Added " << cnt + id(a, u) << " -> " << cnt + id(a, v) << endl;
		add(cnt + id(a, u), cnt + id(a, v));
		insert(v);
	}
}

inline void solve()
{
	cnt = n;
	rep (i, 1, m)
	{
		cin >> a >> b;
		sub[a].clear(); fix(a);
		sort(sub[a].begin(), sub[a].end());

		cout << "sub[4]: ";
		for (auto x : sub[4])
			cout << x << ' ';
		cout << endl;

		cout << "p: ";
		for (int i = h[3]; i; i = e[i].nxt)
			{ cout << e[i].v << ' '; }
		cout << endl;

		cout << id(a, a) << endl;

		add(b, cnt + id(a, a));
		insert(a);
		cnt += sub[a].size();
	}
	init(1); cut(1, 1);
	rep (i, 1, q)
	{
		int u, v; cin >> u >> v;
		cout << LCA(u, v) << endl;
	}
}
}

int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);

	cin >> n >> m >> q;

	rep (i, 2, n)
	{
		int u, v; cin >> u >> v;
		add(u, v);
	}
	prefix(1);

	_30pts::solve();

	return 0;
}

/*
5 2 3
1 4
1 3
4 2
4 5
4 3
3 2
6 9
1 8
5 3
*/

/*

5 2 3

1 4
1 3
4 2
4 5

4 3
3 2

6 9 -> 6
1 8 -> 3
5 3 -> 3

*/