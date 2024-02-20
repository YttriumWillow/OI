#include <iostream>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 110;
const int M = 10010;

int n, m, sum[N];
bool flg = 1;
bool vis[N];

struct Edge { int v, w, nxt; };
Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v, int w)
{ e[++tot] = { v, w, h[u] }; h[u] = tot; }

inline void dfs(int u, int fa, int prv)
{
	if (!flg) return;
	vis[u] = 1; sum[u] = prv;
	for (int i = h[u]; i && flg; i = e[i].nxt)
	{
		int v = e[i].v;
		if (!vis[v])
			dfs(v, u, prv ^ e[i].w);
		else if (v != fa && (sum[u] ^ sum[v] ^ e[i].w)) { flg = 0; return; }
	}
}

inline void solve()
{
	cin >> n >> m; flg = 1;
	rep (i, 1, m)
	{
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}

	rep (i, 1, n)
		if (!vis[i]) dfs(i, 0, 0);

	cout << (flg ? "Yes" : "No") << endl;
}

inline void clear()
{
	fill(h, h + n + 1, 0); tot = 0;
	fill(vis, vis + n + 1, 0);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve(), clear();
	return 0;
}