#include <iostream>
#include <vector>
#include <tuple>
#include <set>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e3 + 10;
const double TLMT = 0.8;

int n, m, k, T, S;
vector<pair<int, int>> G[N];
set<int> cnt;

inline void dfs(int u, int f)
{
	if (u == 1 and f <= k) { cnt.insert(f); }
	for (auto P : G[u])
	{
		int v, w; tie(v, w) = P;
		if (f + w <= k and v != S) dfs(v, f + w);
	}
}

int main()
{
	file("travel");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k >> T;

	rep (i, 1, m)
	{
		int u, v, w; cin >> u >> v >> w;
		G[v].push_back({ u, w });
	}

	rep (i, 1, T)
	{
		cnt.clear();
		cin >> S;
		dfs(S, 0);
		cout << cnt.size() << endl;
	}
	
	return 0;
}

