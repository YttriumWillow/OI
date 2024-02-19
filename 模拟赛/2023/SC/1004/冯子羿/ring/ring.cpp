#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <queue>
#include <tuple>
#include <ctime>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 210;
const int M = 40100;

struct Edge { int u, v; i64 w; int nxt; };
Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v, i64 w)
{ e[++tot] = { u, v, w, h[u] }; h[u] = tot; }

int n; i64 res, ans = LONG_MAX;
bool vis[N], vis2[N];
bool use[M << 1];


// const int T = 0.9;

inline void dfs2(int u, i64 d)
{
	if (u == 1) { res += d; ans = min(ans, res); }
	vis2[u] = 1;
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (!vis2[v]) { dfs2(v, d + use[i] ? 0 : e[i].w); }
	}
}

inline void dfs1(int u)
{
	if (u == n)
	{
		res = 0;
		fill(vis2, vis2 + n + 1, 0);
		for (int i = 1; i <= tot; ++i)
			if (use[i])
				res += e[i].w;

		for (int i = 1; i <= tot; ++i)
			cout << use[i] << " \n"[i == tot];

		dfs2(n, 0);

		// ans = min(ans, res);
	}

	vis[u] = 1;
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (!vis[v])
		{
			use[i] = 1;
			dfs1(v);
			use[i] = 0;
		}
	}

}

inline void bfs2(vector<int> lst)
{
	queue< pair<int, vector<int>> > q;
	vector<int> t;
	q.push({ n, t });
	while (!q.empty())
	{
		int u; vector<int> p;
		tie(u, p) = q.front(); q.pop();
		if (u == 1)
		{
			i64 res = 0;
			set<int> s;
			
			for (auto x : lst)
				s.insert(x);

			for (auto x : p)
				s.insert(x);

			// for (auto x : lst)
			// 	cout << x << " \n"[x == lst.back()];
			// for (auto x : p)
			// 	cout << x << " \n"[x == p.back()];

			for (auto x : s) res += e[x].w;

			// if ((double)clock() / CLOCKS_PER_SEC > T) { cout << ans << endl; exit(0); }

			ans = min(ans, res);
		}
		for (int i = h[u]; i; i = e[i].nxt)
		{
			int v = e[i].v;
			bool f = 1;
			for (auto x : p) if (x == i) f = 0;
			if (f)
			{
				p.push_back(i);
				q.push({ v, p });
			}
		}
	}
}

inline void bfs1()
{
	queue< pair<int, vector<int>> > q;
	vector<int> t;
	q.push({ 1, t });
	while (!q.empty())
	{
		int u; vector<int> p;
		tie(u, p) = q.front(); q.pop();
		if (u == n)
		{

			// for (auto x : p)
			// 	cout << x << " \n"[x != p.back()];

			bfs2(p);
		}
		for (int i = h[u]; i; i = e[i].nxt)
		{
			int v = e[i].v;
			bool f = 1;
			for (auto x : p) if (x == i) f = 0;
			if (f)
			{
				p.push_back(i);
				q.push({ v, p });
			}
		}
	}
}


int main()
{
	// file("ring");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1, x; j <= n; ++j)
		{
			cin >> x;
			if (x != 0) add(i, j, x);
		}

	bfs1();

	cout << ans << endl;

	return 0;
}