#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

inline int fpow(int a, int k)
{
	int res = 1;
	for (; k; k >>= 1)
	{
		if (k & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
	}
	return res;
}

inline void dfs()
{
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 2, n)
	{
		int u, v;
		cin >> u >> v;
		add(u, v); add(v, u);
	}

	prefix(1, 0);

	ret[1] = 1;
	rep (i, 1, n)
		fac[i] = 1ll * fac[i - 1] * i % mod;

	dfs(1, 0);

	rep (i, 1, n)
		res = (res + fac[n] * )

	return 0;
}