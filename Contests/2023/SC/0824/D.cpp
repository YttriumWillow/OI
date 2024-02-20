#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 3e5 + 10;
const int M = 3e5 + 10;
const i64 inf = 0x3f3f3f3f3f3f3f3f;

int n;
i64 lmt, d, ans = inf;
i64 d1[N], d2[N];

struct Edge { int v; i64 a, b; int nxt; inline i64 w() { return a + b * d; } };
Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v, i64 a, i64 b)
{ e[++tot] = { v, a, b, h[u] }; h[u] = tot; }

inline void dfs(int u, int pre)
{
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (v == pre) continue;
		dfs(v, u);
		i64 a = d1[v] + e[i].w();
		if (a > d1[u]) 		d2[u] = d1[u], d1[u] = a;
		else if (a > d2[u]) d2[u] = a;
	}
}

inline i64 calc(i64 mid)
{
	d = mid;
	i64 res = -inf;
	fill(d1 + 1, d1 + n + 1, 0);
	fill(d2 + 1, d2 + n + 1, 0);
	dfs(1, 0);
	for (int i = 1; i <= n; ++i)
		res = max(res, d1[i] + d2[i]);
	return res;
}

signed main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> lmt;
	for (int i = 1, x, y; i < n; ++i)
	{
		i64 a, b;
		cin >> x >> y >> a >> b;
		add(x, y, a, b);
		add(y, x, a, b);
	}
	i64 l = 0, r = lmt;
	while (l < r)
	{
		i64 m1 = l + (r - l) / 3;
		i64 m2 = r - (r - l) / 3;
		if (calc(m1) > calc(m2))
			l = m1 + 1;
		else
			r = m2 - 1;
	}
	cout << l << endl << calc(l) << endl;
	return 0;
}