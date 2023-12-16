#include <set>
#include <ctime>
#include <random>
#include <iostream>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 3e3 + 10;

int n, m, d[N], W[N];
i64 res;

struct Graph
{
	struct Edge { int v, w, nxt; };
	Edge e[N << 1]; int h[N], tot;
	Edge& operator[](int x) { return e[x]; }
	inline void add(int u, int v, int w)
	{ e[++tot] = { v, w, h[u] }; h[u] = tot; }
} G;

namespace Sub1
{
inline void dfs(int u, int fa, set<int> P)
{
	d[u] = *P.begin();
	for (int i = G.h[u]; i; i = G[i].nxt)
	{
		int v = G[i].v;
		if (v == fa) continue;
		set<int> T = P; T.erase(G[i].w);
		dfs(v, u, T);
	}
}
inline void solve()
{
	rep (i, 2, n)
	{
		int u, v; cin >> u >> v;
		G.add(u, v, 0); G.add(v, u, 0);
	}

	set<int> S; S.insert(n - 1);
	rep (i, 1, n - 1) S.insert(W[i] = i - 1);

	do {
		i64 cnt = 0;
		rep (i, 1, n - 1) G[i * 2 - 1].w = G[i * 2].w = W[i];
		// rep (i, 1, n - 1) cout << W[i] << " \n"[i == n - 1];
		rep (i, 1, n) 
		{
			// fill(d + 1, d + n + 1, 0);
			dfs(i, 0, S);
			rep (j, 1, n) if (j ^ i) cnt += d[j];

			// cout << "* " << i << ": ";
			// rep (j, 1, n) cout << d[j] << " \n"[j == n];

		}
		res = max(res, cnt / 2);
	} while (next_permutation(W + 1, W + n));

	cout << res << endl;
}
}


namespace Sub2
{
inline void dfs(int u, int fa, set<int> P)
{
	d[u] = *P.begin();
	for (int i = G.h[u]; i; i = G[i].nxt)
	{
		int v = G[i].v;
		if (v == fa) continue;
		set<int> T = P; T.erase(G[i].w);
		dfs(v, u, T);
	}
}
inline void solve()
{
	rep (i, 2, n)
	{
		int u, v; cin >> u >> v;
		G.add(u, v, 0); G.add(v, u, 0);
	}

	set<int> S; S.insert(n - 1);
	rep (i, 1, n - 1) S.insert(W[i] = i - 1);

	while ((double)clock() / CLOCKS_PER_SEC < 2.5)
	{
		shuffle(W + 1, W + n, mt19937(random_device{}()));
		i64 cnt = 0;
		rep (i, 1, n - 1)
			G[i * 2 - 1].w = G[i * 2].w = W[i];
		rep (i, 1, n)
		{
			dfs(i, 0, S);
			rep (j, 1, n) if (j ^ i) cnt += d[j];
		}
		res = max(res, cnt / 2);
	}

	cout << res << endl;
}
}

int main()
{
	file("tree");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	if (n <= 9) Sub1::solve();
	else Sub2::solve();
	return 0;
}