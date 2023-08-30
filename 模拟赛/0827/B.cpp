#include <iostream>
#include <vector>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define pb push_back

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;

int n, m, k, lmt;
int len, s, t;
int cnt[N], cir[N], dep[N];
bool col[N], vis[N];

struct Edge { int v, nxt; };
Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v)
{ e[++tot] = { v, h[u] }; h[u] = tot; }

inline void dfs2(int u)
{
	cir[++len] = u; dep[u] = len;
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (!dep[v]) dfs2(v);
		else if (dep[v] + 1 == dep[u]) ++cnt[u];
		if (dep[v] + 1 < dep[u] || cnt[u] == 2)
		{
			int siz = dep[u] - dep[v] + 1;
			if (siz <= k)
			{
				cout << 2 << endl << siz << endl;
				for (int j = dep[v]; j <= dep[u]; ++j)
					cout << cir[j] << ' ';
				exit(0);
			}
			else if (siz <= lmt)
			{
				lmt = siz;
				s = u, t = v;
			}
		}
	}
	--len;
}

inline void dfsx(int u)
{
	cir[++len] = u; dep[u] = len;
	if (u == t)
	{
		cout << 1 << endl;
		for (int j = 1; j <= k; j += 2)
			cout << cir[j] << ' ';
		exit(0);
	}
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (u == s && v == t) continue;
		if (!dep[v]) dfsx(v);
	}
	--len;
}

inline void dfst(int u)
{
	vis[u] = 1;
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (!vis[v])
		{
			col[v] = col[u] ^ 1;
			dfst(v);
		}
	}
}

inline void task()
{
	dfs2(1);
	if (s) fill(dep + 1, dep + n + 1, 0), dfsx(s);
	cout << 1 << endl;
	dfst(1);
	vector<int> res[2];
	for (int i = 1; i <= n; ++i)
		res[col[i]].pb(i);
	if ((int)res[0].size() >= (k + 1) / 2)
	{
		for (int i = 1; i <= (k + 1) / 2; ++i)
			cout << res[0][i - 1] << ' ';
	}
	else
	{
		for (int i = 1; i <= (k + 1) / 2; ++i)
			cout << res[1][i - 1] << ' ';
	}
}

int main()
{
	// freopen("graph.in", "r", stdin);
	// freopen("graph.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k; lmt = n;
	for (int i = 1, u, v; i <= m; ++i)
	{
		cin >> u >> v;
		add(u, v); add(v, u);
	}
	task();
	return 0;
}