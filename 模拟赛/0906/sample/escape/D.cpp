#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e5 + 10;
const int M = 2e5 + 10;
const int K = 2e5 + 10;
const int inf = 0x3f3f3f3f;

int n, m, k, ans, p[N];

struct Edge { int b, c, d, w, nxt; };
Edge e[M << 1]; int h[N], tot;
inline void add(int a, int b, int c, int d, int w)
{ e[++tot] = { b, c, d, w, h[a] }; h[a] = tot; }

inline void dfs(int x, int y, int res)
{
	// if (res > ans) return;
	if (x == n) { ans = min(res + p[x] * abs(y - m), ans); return; }
	for (int i = h[x]; i; i = e[i].nxt)
	{
		int nx = e[i].c, ny = e[i].d, rx = p[x] * abs(y - e[i].b), w = e[i].w;
		dfs(nx, ny, res + rx - w);
	}
	// cerr << "to x:" << x << " y:" << y << " res=" << res << endl;
}

inline void solve()
{
	cin >> n >> m >> k; ans = inf;
	for (int i = 1; i <= n; ++i)
		cin >> p[i];
	for (int i = 1; i <= k; ++i)
	{
		int a, b, c, d, w;
		cin >> a >> b >> c >> d >> w;
		add(a, b, c, d, w);
	}
	add(0, 0, 1, 1, 0);
	dfs(0, 0, 0);

	if (ans == inf) cout << "NO ESCAPE" << endl;
	else cout << ans << endl;

	tot = 0; ans = inf;
	fill(h, h + n + 1, 0);
}

int main()
{
	freopen("escape.in", "r", stdin);
	freopen("escape.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();
	return 0;
}