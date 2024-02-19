#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

inline void solve()
{
	i64 n, x, p; cin >> x >> p, n = x * p * p;
	for (int a = 1; a + 2 <= n && a <= 120; ++a)
		for (int b = 1; a * b + a + b <= n && b <= 120; ++b)
			if ((n - a * b) % (a + b) == 0) { cout << a << ' ' << b << ' ' << (n - a * b) / (a + b) << endl; return;}
	cout << -1 << endl;
}
signed main()
{
	freopen("construct.in", "r", stdin);
	freopen("construct.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();
	return 0;
}