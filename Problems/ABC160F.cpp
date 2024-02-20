#include <iostream>

#define int long long
#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e5 + 10;
const int M = 2e5 + 10;
const i64 mod = 1e9 + 7;

int n, fac = 1;
int siz[N], f[N];

struct Edge { int v, nxt; };
Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v)
{ e[++tot] = { v, h[u] }; h[u] = tot; }

inline int fpow(int a, int k)
{
	int res = 1;
	for (; k; k >>= 1)
	{
		if (k & 1) res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}

inline int inv(int x) { return fpow(x, mod - 2); }

inline void dfs1(int u, int fa)
{
	siz[u] = 1;
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (v == fa) continue;
		dfs1(v, u);
		siz[u] += siz[v];
	}
}

inline void dfs2(int u, int fa)
{
	if (u != 1)
		f[u] = (f[fa] * (n - siz[u]) % mod * inv(siz[u])) % mod;
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (v == fa) continue;
		dfs2(v, u);
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1, u, v; i < n; ++i)
	{
		cin >> u >> v;
		add(u, v); add(v, u);
	}

	dfs1(1, 0); f[1] = 1;

	for (int i = 1; i <= n; ++i)
		f[1] = (f[1] * siz[i]) % mod;

	dfs2(1, 0);

	for (int i = 1; i <= n; ++i)
		fac = fac * i % mod;
	for (int i = 1; i <= n; ++i)
		cout << fac * inv(f[i]) % mod << endl;
	return 0;
}