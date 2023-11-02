#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, m, q;

struct Edge { int v, nxt; };
Edge e[M << 1]; int h[N], tot;
inline void add(int u, int v)
{ e[++tot] = { v, h[u] }; h[u] = tot; }

namespace _40
{
int l, r; i64 res = 0;
inline void dfs(int u, int cnt)
{
	// cout << u << ':' << cnt << ' ';
	if (l <= u and u <= r) { ++cnt, res += cnt; };
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		dfs(v, cnt);
	}
}
inline void solve()
{
	cin >> q;
	while (q--)
	{
		cin >> l >> r;
		l = (l ^ res) % n + 1; r = (r ^ res) % n + 1;
		if (l > r) swap(l, r);
		// cout << l << " -> " << r << endl;
		res = 0; dfs(1, 0);
		cout << res << endl;
	}
}
}

int main()
{
	file("easy");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 2, n) { int x; cin >> x; add(x, i); }

	if (n <= 1000) _40::solve(), exit(0);

	cin >> q;
	while (q--)
	{
		int l, r; cin >> l >> r;
		// cout << query(l, r) << endl;
	}
	return 0;
}