// Edge{v,w,nxt} -> vector<Edge{v,w}>
// 950+ ms -> 100+ ms
// this is such the confidence

#include <iostream>
#include <queue>
#include <vector>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, m, q;
i64 a[N]; bool vis[N];

struct Edge
{
	int v, w;
	friend bool	operator < (const Edge& A, const Edge& B)
	{ return A.w > B.w; }
};
vector<Edge> G[N];
inline void add(int u, int v, int w) { G[u].push_back({ v, w }); }

inline i64 bfs(int x, i64 k)
{
	fill(vis, vis + n + 1, 0);

	queue<int> Q;
	priority_queue<Edge> E;

	i64 totk = k; vis[x] = 1; Q.push(x);

	while (!Q.empty())
	{
		int u = Q.front(); Q.pop(); totk += a[u];
		for (auto P : G[u])
			if (!vis[P.v]) E.push(P);

		while (!E.empty())
		{
			auto P = E.top();
			int v = P.v, w = P.w;
			if (w > totk) break;
			if (vis[v]) { E.pop(); continue; }
			Q.push(v); vis[v] = 1; E.pop();
		}
	}

	return totk;
}

int main()
{
	file("travel");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> q;

	rep (i, 1, n) cin >> a[i];

	rep (i, 1, m)
	{
		int u, v, w; cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}

	rep (i, 1, q)
	{
		int x, k; cin >> x >> k;
		cout << bfs(x, k) << endl;
	}

	return 0;
}