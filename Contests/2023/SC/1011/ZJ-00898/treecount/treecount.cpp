#include <iostream>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 5e3 + 10;
const int M = 5e3 + 10;
const int mod = 998244353;

int n, m;
int a[N], pw[N] = { 1 };

struct Edge { int v, nxt; };
Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v)
{ e[++tot] = { v, h[u] }; h[u] = tot; }

namespace Sub1
{
i64 res = 0, cnt = 0;
inline void dfs(int u, int mx)
{	
	if (a[u] >= mx) ++cnt;
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		dfs(v, max(mx, a[u]));
	}
}
inline void solve()
{
	for (int i = 1; i <= n; ++i)
		a[i] = i;
	do {
		cnt = 0;
		dfs(1, 0);
		res = (res + pw[cnt]) % mod;
	} while (next_permutation(a + 1, a + n + 1));
	cout << res << endl;
}
}

int main()
{
	file("treecount");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 2, x; i <= n; ++i)
		cin >> x, add(x, i);

	for (int i = 1; i <= n; ++i)
		pw[i] = 1ll * pw[i - 1] * m % mod;

	if (n <= 10) Sub1::solve(), exit(0);

	return 0;
}