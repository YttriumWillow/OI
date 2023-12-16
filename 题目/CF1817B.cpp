#include <iostream>
#include <cstring>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2010;

int n, m, id, f, top;
int to[N << 1], ne[N << 1], head[N];
int deg[N], st[N], vis[N], col[N];

inline void add(int x, int y) { to[++id] = y, ne[id] = head[x], head[x] = id; }

inline void dfs(int u, int fa, int rt)
{
	if (f) return;
	st[++top] = u, vis[u] = 1;
	for (int i = head[u]; i && !f; i = ne[i])
	{
		int v = to[i];
		if (v == fa) continue;
		if (v == rt && fa != rt)
		{
			memset(col, 0, sizeof col);
			for (int i = 1; i <= top; i++) col[st[i]] = 1;
			int cnt = 0;
			for (int j = head[rt]; j && cnt < 2; j = ne[j])
				if (!col[to[j]]) cnt++;
			if (cnt < 2) continue;
			cout << "YES" << endl << top + 2 << endl;
			for (int i = top; i > 1; i--) cout << st[i] << ' ' << st[i - 1] << endl;
			cout << rt << ' ' << u << endl; cnt = 0;
			for (int j = head[rt]; j && cnt < 2; j = ne[j])
				if (!col[to[j]]) cout << rt << ' ' << to[j] << endl, cnt++;
			f = 1; return;
		}
		if (!vis[v]) dfs(v, u, rt);
	}
	--top;
}
void solve()
{
	cin >> n >> m; id = f = 0;

	memset(head, 0, sizeof head);
	memset(deg, 0, sizeof deg);

	for (int x, y; m--;)
	{
		cin >> x >> y;
		add(x, y), add(y, x);
		deg[x]++, deg[y]++;
	}
	for (int i = 1; i <= n && !f; i++)
	{
		if (deg[i] < 4) continue;
		memset(vis, 0, sizeof vis);
		dfs(i, 0, i), top = 0;
	}
	if (!f) cout << "NO" << endl;
}

int main()
{
	int T; cin >> T;
	while (T--) solve();

	return 0;
}
