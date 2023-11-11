#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e3 + 10;
const int M = 3e5 + 10;
const double eps = 1e-5;
const int inf = 0x3f3f3f3f;
const double infd = 1e18;

struct Graph
{
	struct Edge { int v; double w; int typ, nxt; };
	Edge e[M << 1]; int h[N], tot = 1;
	inline void add(int u, int v, double w, int typ)
	{ e[++tot] = { v, w, typ, h[u] }; h[u] = tot; }
} G;

int n, s, t;
int cnt[N]; double d[N];
bool vis[N];

inline bool SPFA(double T)
{
	fill(d, d + n + 1, -infd);
	fill(cnt, cnt + n + 1, 0);
	fill(vis, vis + n + 1, 0);
	d[n + 1] = 0;
	queue<int> Q; Q.push(n + 1); vis[n + 1] = 1;

	while (!Q.empty())
	{
		int u = Q.front(); Q.pop(); vis[u] = 0;
		for (int i = G.h[u]; i; i = G.e[i].nxt)
		{
			int v = G.e[i].v, typ = G.e[i].typ;
			double w = G.e[i].w;
			if (typ == 1) w = log2(w - T);
			if (typ == 2) w = -log2(w + T);
			if (d[v] < d[u] + w)
			{
				d[v] = d[u] + w; cnt[v] = cnt[u] + 1;
				if (cnt[v] >= n + 2) return 1;
				else if (!vis[v]) { vis[v] = 1; Q.push(v); }
			}
		}
	}

	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> s >> t;

	double l = 0, r = 10;

	rep (i, 0, n) G.add(n + 1, i, 0, 3);

	rep (i, 1, s)
	{
		int o, A, B; double k; cin >> o >> A >> B >> k;
		G.add(B, A, k, o);
		if (o == 1) { r = min(r, k); }
	}

	rep (i, 1, t)
	{
		int c; double x;
		cin >> c >> x;
		G.add(0, c, log2(x), 3);
		G.add(c, 0, -log2(x), 3);
	}
	if (!SPFA(0)) { cout << -1 << endl; return 0; }
	while (r - l > eps)
	{
		double mid = (l + r) / 2;
		SPFA(mid) ? l = mid : r = mid;
	}

	cout << l << endl;
	return 0;
}