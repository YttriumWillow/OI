#include <iostream>
#include <algorithm>
#include <cmath>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e5 + 10;

int n, k;
i64 A[N], B[N], bsc;

namespace Sub1
{
inline void solve()
{
	i64 ans = 0, res = 0;
	sort(A + 1, A + n + 1);
	sort(B + 1, B + n + 1, greater<int>());
	rep (i, 1, n) res += llabs(A[i] - B[i]);

	while (k > n - 1) k -= 2;
	if (k == n - 1) { cout << res << endl; return; }
	rep (i, 1, n) rep (j, i + 1, n)
	{
		res += llabs(A[i] - B[j]) + llabs(A[j] - B[i]);
		res -= llabs(A[i] - B[i]) + llabs(A[j] - B[j]);
		ans = max(ans, res);
		res += llabs(A[i] - B[i]) + llabs(A[j] - B[j]);
		res -= llabs(A[i] - B[j]) + llabs(A[j] - B[i]);
	}
	cout << ans << endl;
}
}

namespace Sub2_1
{
inline void solve()
{
	i64 ans = 0, res = bsc;
	rep (i, 1, n) rep (j, i + 1, n)
	{
		res += llabs(A[i] - B[j]) + llabs(A[j] - B[i]);
		res -= llabs(A[i] - B[i]) + llabs(A[j] - B[j]);
		ans = max(ans, res);
		res += llabs(A[i] - B[i]) + llabs(A[j] - B[j]);
		res -= llabs(A[i] - B[j]) + llabs(A[j] - B[i]);
	}
	cout << ans << endl;
}
}

namespace Sub2_2
{
inline void solve()
{
	i64 ans = 0, res = bsc;
	rep (i, 1, n) rep (j, i + 1, n)
	{
		rep (x, 1, n) if (x != i) rep (y, x + 1, n) if (y != j)
		{
			res += llabs(A[i] - B[j]) + llabs(A[j] - B[i]);
			res += llabs(A[y] - B[x]) + llabs(A[x] - B[y]);
			res -= llabs(A[i] - B[i]) + llabs(A[j] - B[j]);
			res -= llabs(A[x] - B[x]) + llabs(A[y] - B[y]);
			ans = max(ans, res);
			res += llabs(A[i] - B[i]) + llabs(A[j] - B[j]);
			res += llabs(A[x] - B[x]) + llabs(A[y] - B[y]);
			res -= llabs(A[i] - B[j]) + llabs(A[j] - B[i]);
			res -= llabs(A[x] - B[y]) + llabs(A[y] - B[x]);
		}
	}
	cout << ans << endl;
}
}

inline void solve()
{
	cin >> n >> k; bsc = 0;
	rep (i, 1, n) cin >> A[i];
	rep (i, 1, n) cin >> B[i];
	rep (i, 1, n) bsc += llabs(A[i] - B[i]);

	if (k > n * n) { Sub1::solve(); return; }
	if (k == 1) { Sub2_1::solve(); return; }
	if (k == 2 and n <= 75) { Sub2_2::solve(); return; }

}

int main()
{
	file("swap");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();
	return 0;
}