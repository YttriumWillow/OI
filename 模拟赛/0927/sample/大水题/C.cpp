#include <iostream>

#include <set>
#include <queue>
#include <vector>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 5e5 + 10;
const int M = 1e6 + 10;

int n, m, k, leaf;

struct Edge { int v, nxt; };

Edge e[M << 1]; int h[N], tot = 1;
inline void add(int u, int v)
{ e[++tot] = { v, h[u] }, h[u] = tot; }

set<int> g[N];

int dfncnt, dcccnt;
int low[N], dfn[N];
int dcc[N], deg[N], siz[N];
bool vis[N];

bool b[M << 1];

inline void tarjan(int u, int ine)
{
	dfn[u] = low[u] = ++dfncnt;
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (!dfn[v])
		{
			tarjan(v, i);
			low[u] = min(low[u], low[v]);
			if (dfn[u] < low[v]) b[i] = b[i ^ 1] = 1;
		}
		if (i != (ine ^ 1))
			low[u] = min(low[u], dfn[v]);
	}
}

inline void dfs(int u)
{
	dcc[u] = dcccnt; ++siz[dcccnt];
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (!b[i] && !dcc[v]) dfs(v);
	}
}

inline int fix(int u, int fa)
{
	if (siz[u] > 1) return 0;
	int res = 0;
	for (auto v : g[u])
	{
		if (v == fa) continue;
		res += fix(v, u);
	}
	return res + 1;
}

inline void clear()
{
	fill(h, h + n + 1, 0); tot = 1;
	for (int i = 1; i <= dcccnt; ++i) g[i].clear();
	dfncnt = dcccnt = 0;
	fill(dfn, dfn + n + 1, 0);
	fill(low, low + n + 1, 0);
	fill(siz, siz + n + 1, 0);
	fill(dcc, dcc + n + 1, 0);
	fill(deg, deg + n + 1, 0);
	fill(vis, vis + n + 1, 0);
	fill(b, b + m + m + 1, 0);
}

inline void solve()
{
	clear();

	for (int i = 1, u, v; i <= m; ++i)
	{
		cin >> u >> v;
		add(u, v); add(v, u);
	}

	if (m == n - 1) { cout << (n - 1) / k << endl; return; }

	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i, 0);
	for (int i = 1; i <= n; ++i)
		if (!dcc[i]) ++dcccnt, dfs(i);	

	// for (int i = 1; i <= n; ++i)
	// 	cerr << dcc[i] << " \n"[i == n];

	for (int u = 1; u <= n; ++u)
		for (int i = h[u]; i; i = e[i].nxt)
		{
			int v = e[i].v;
			if (dcc[u] != dcc[v])
			{
				g[dcc[u]].insert(dcc[v]);
				g[dcc[v]].insert(dcc[u]);
			}
		}

	for (int u = 1; u <= dcccnt; ++u)
		for (auto v : g[u])
			++deg[u], ++deg[v];
	for (int i = 1; i <= dcccnt; ++i)
		deg[i] >>= 1;

	// for (int i = 1; i <= dcccnt; ++i)
	// 	cerr << deg[i] << " \n"[i == dcccnt];

	int res = 0, cnt = 0;
	queue<int> q;

	for (int i = 1; i <= dcccnt; ++i)
		if (deg[i] == 1)
			q.push(i);
			// cntdel += fix(i, 0);

	while (!q.empty())
	{
		int u = q.front(); q.pop(); --deg[u];
		for (auto v : g[u])
		{
			if (deg[v] == 2 && siz[v] == 1)
				q.push(v), --deg[v], ++cnt;
			if (cnt >= k) cnt -= k, ++res;
		}
	}

	// cerr << cntdel << endl;

	cout << res << endl;
}

int main()
{
	file("dst");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	while (cin >> n >> m >> k && (n || m || k)) solve();

	return 0;
}