#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, m;
int siz[N], dep[N];

struct Edge { int v, nxt; };
Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v)
{ e[++tot] = { v, h[u] }; h[u] = tot; }

inline void dfs(int u, int fa)
{
	dep[u] = dep[fa] + 1;
	siz[u] = 1;

	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (v == fa) continue;
		dfs(v, u); siz[u] += siz[v];
	}
}

int main()
{
	file("dfs");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	rep (i, 1, n - 1)
	{
		int u, v; cin >> u >> v;
		add(u, v), add(v, u);
	}

	dfs(1, 0);

	for (int i = 1; i <= n; ++i)
		cout << dep[i] << ' ' << n - siz[i] + 1 << endl;

	return 0;
}