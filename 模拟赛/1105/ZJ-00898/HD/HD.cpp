#include <iostream>
#include <bitset>

#define i64 long long
#define ull unsigned long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1010;
const int M = N;
const int mod = 1e9 + 7;

int n, m, q, k, p[N];
ull reach[N][N];
int now, cnt;

struct Graph
{
	struct Edge { int v, nxt, id; };
	Edge e[M << 1]; int h[N], tot = 1;
	inline void add(int u, int v, int id)
	{ e[++tot] = { v, h[u], id }; h[u] = tot; }
} T;

inline void dfs(int u, int ine)
{
	for (int i = T.h[u]; i; i = T.e[i].nxt)
	{
		int v = T.e[i].v;
		if (i == (ine ^ 1)) continue;
		// rep (t, T.e[i].id, n - 1)
		reach[now][T.e[i].id] = reach[now][T.e[ine].id] | (1ull << (v - 1));
		// if (now == 3) cout << "!!! " << u << "->" << v << ' ' << T.e[i].id << ' ' << bitset<5>(reach[3][1]) << endl;
		// if (T.e[i].id == 1)
		// {
		// 	cout <<  << endl;
		// 	cout << bitset<5>(reach[3][2]) << endl;
		// }

		// int t = i >> 1;
		// reach[now][t] = reach[now][t - 1] | (1ull << (v - 1));
		dfs(v, i);
	}
}

inline void find(int i, ull st)
{
	if (i == k) { cnt = cnt + 1; return; }
	rep (j, 0, n - 1)
	{
		if (st & reach[p[i]][j]) break;
		dfs(j, st | reach[p[i]][j]);
	}
}

inline i64 solve()
{
	cnt = 0;
	find(1, 0ull);
	return cnt;
}

int main()
{
	file("HD");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 1, n - 1)
	{
		int u, v; cin >> u >> v;
		T.add(u, v, i); T.add(v, u, i);
	}

	rep (i, 1, n) rep (j, 0, n - 1) reach[i][j] = (1ull << (i - 1));
	for (now = 1; now <= n; ++now)
		dfs(now, 0);

	cin >> q;
	while (q--)
	{
		cin >> k;
		rep (i, 1, k) cin >> p[i];
		cout << solve() << endl;
	}

	// rep (i, 1, n)
	// rep (j, 0, n - 1)
	// cout << bitset<5>(reach[i][j]) << " \n"[j == n - 1];

	return 0;
}