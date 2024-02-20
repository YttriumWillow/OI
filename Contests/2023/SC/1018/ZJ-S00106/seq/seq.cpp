#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

constexpr int N = 505;
constexpr int V = 1e6 + 10;
constexpr int mod = 1e9 + 7;

int n, l[N], r[N], lmt;
i64 sum[V], f[2][V];

int main()
{
	// file("seq");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 1, n)
	{
		cin >> l[i] >> r[i];
		lmt = max(lmt, r[i]);
	}

	fill(sum, sum + lmt + 1, 1);

	rep (i, 1, n)
	{
		i64 cnt = 0;
		rep (j, l[i], r[i])
			f[i & 1][j] = sum[j - 1];
		rep (j, 1, lmt)
		{
			f[(i & 1) ^ 1][j] = 0;
			cnt = (cnt + f[i & 1][j] % mod) % mod;
			sum[j] = (cnt + sum[j]) % mod;
		}
	}	

	cout << sum[lmt] - 1 << endl;
	return 0;
}