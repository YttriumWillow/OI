#include <iostream>

#define i64 long long 
#define endl '\n'
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5e5 + 10;

int n, m;
int a[N], b[N], c[N], p[N];
i64 f[N], g[N], sumb[N];

inline void solve()
{
	cin >> m;
	rep (i, 1, m) cin >> p[i];

	// f[]: all 1 -> cur
	// g[]: all 0 -> cur

	rep (i, 1, m)
	{
		g[i] = g[i - 1] + c[p[i]];
		f[i] = min(
			a[p[i] - 1] + g[i - 1],
			f[i - 1] + sumb[p[i] - 1] - sumb[p[i - 1]]
		);
	}

	cout << min(g[m] + a[n], f[m] + sumb[n] - sumb[p[m]]) << endl;

	f[0] = g[0] = 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 1, n) cin >> a[i];
	rep (i, 1, n) cin >> b[i];
	rep (i, 1, n) cin >> c[i];
	rep (i, 1, n) sumb[i] = sumb[i - 1] + b[i];
	rep (i, 1, n) a[i] = min(a[i], a[i - 1] + b[i]);

	int Q; cin >> Q;
	while (Q--) solve();
	return 0;
}