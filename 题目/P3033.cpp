#include <iostream>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 610;
const int M = 610 * 610;

int n, cnt, res;
i64 x1[N], x2[N], y1[N], y2[N];
int m[N], p[N]; bool vis[N];

struct Graph
{
	struct Edge { int v, nxt; };
	Edge e[M << 1]; int h[N], tot = 1;
	inline void add(int u, int v)
	{ e[++tot] = { v, h[u] }; h[u] = tot; }
} G;

inline bool match(int u)
{
	vis[u] = 1;
	for (int i = G.h[u]; i; i = G.e[i].nxt)
	{
		int v = G.e[i].v;
		if (vis[m[v]]) continue;
		if (!m[v] or match(m[v]))
			return m[v] = u, 1;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 1, n)
	{
		cin >> x1[i] >> y1[i];
		cin >> x2[i] >> y2[i];
		if (x1[i] > x2[i]) swap(x1[i], x2[i]);
		if (y1[i] > y2[i]) swap(y1[i], y2[i]);
		p[i] = x1[i] == x2[i] ? (++cnt) : 0;
	}
	rep (i, 1, n) rep (j, i + 1, n)
	{
		if (p[i] and !p[j])
			if (x1[i] >= x1[j] and x2[i] <= x2[j] and y1[i] <= y1[j] and y2[i] >= y2[j])
				G.add(i, j + cnt);
		if (!p[i] and p[j])
			if (x1[i] <= x1[j] and x2[i] >= x2[j] and y1[i] >= y1[j] and y2[i] <= y2[j])
				G.add(j, i + cnt);
	}
	rep (i, 1, n) if (p[i])
	{
		fill(vis, vis + n + 1, 0);
		if (match(i)) ++res;
	}

	cout << n - res << endl;

	return 0;
}