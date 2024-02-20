#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e5 + 10;

int n, m, dep[N];
i64 a[N], b[N], c[N];

struct Edge { int v, nxt; };
Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v)
{ e[++tot] = { v, h[u] }; h[u] = tot; }

inline void dfs(int u, int fa)
{
	dep[i] = dep[fa] + 1;
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (v == fa) continue;
		dfs(v, u);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	rep (i, 1, n)
		cin >> a[i] >> b[i] >> c[i];
	rep (i, 1, n - 1)
	{
		cin >> u >> v;
		add(u, v); add(v, u);
	}
	dfs(1, 0);
	rep (i, 1, n)
	{
		
	}
	return 0;
}