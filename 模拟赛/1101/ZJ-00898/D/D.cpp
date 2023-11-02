#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 5e5 + 10;
const int M = 5e5 + 10;
const int mod = 998244353;

int n, m, rt;
int dg[N], f[N];
int fac[N], siz[N];
i64 res, ans;

struct Edge { int v, nxt; };
Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v)
{ e[++tot] = { v, h[u] }; h[u] = tot; }

inline void dfs(int u, int fa)
{
	siz[u] = 1;
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (v == fa) continue;
		dfs(v, u);

		siz[u] += siz[v];
		res = (res * fac[siz[v]]) % mod;
	}
}

inline i64 fpow(i64 a, i64 k)
{
	i64 res = 1;
	for (; k; k >>= 1)
	{
		if (k & 1) res = (1ll * res * a) % mod;
		a = (1ll * a * a) % mod;
	}
	return res;
}

int main()
{
	file("neo");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; res = 1;
	fac[0] = 1;
	rep (i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;

	rep (i, 2, n)
	{
		int u, v; cin >> u >> v;
		++dg[u], ++dg[v];
		add(u, v); add(v, u);
	}

	// rep (i, 1, n)
	// {
	// 	res = 1;
	// 	dfs(i, 0);
	// 	ans = (ans + res) % mod;
	// }

	// dfs(rt, 0);

	cout << fpow(2, n - 1) % mod << endl;
	return 0;
}