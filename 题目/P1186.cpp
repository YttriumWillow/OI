#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define fir first
#define sec second
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e3 + 10;
const int M = 1e6 + 10;
const int inf = 0x3f3f3f3f;

int n, m, res;
int d[N], prv[N]; bool vis[N];

struct Graph
{
	struct Edge { int v, w, nxt; };
	Edge e[M << 1]; int h[N], tot = 1;
	Edge& operator[](int x) { return e[x]; }
	inline void add(int u, int v, int w)
	{ e[++tot] = { v, w, h[u] }; h[u] = tot; }
} G;

vector<int> P;

inline int Dijkstra()
{
	fill(vis, vis + n + 1, 0);
	fill(d, d + n + 1, inf);
	d[1] = 0;

	rep (k, 1, n)
	{
		int u = 0; rep (p, 1, n) if (!vis[p] and d[p] < d[u]) u = p;
		vis[u] = 1;
		for (int i = G.h[u]; i; i = G[i].nxt)
		{
			int v = G[i].v, w = G[i].w;
			if (d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				prv[v] = i;
			}
		}
	}
	return d[n];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	rep (i, 1, m)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G.add(u, v, w);
		G.add(v, u, w);
	}

	res = Dijkstra();

	for (int e = n; e ^ 1; e = G[prv[e] ^ 1].v)
		P.push_back(prv[e]);

	shuffle(P.begin(),P.end(), mt19937(random_device{}()));

	for (auto E : P)
	{
		int t = G[E].w;
		G[E].w = G[E ^ 1].w = inf;
		res = max(res, Dijkstra()); 
		G[E].w = G[E ^ 1].w = t;
		if (1.0 * clock() / CLOCKS_PER_SEC > 0.97) break;
	}

	cout << res << endl;


	return 0;
}