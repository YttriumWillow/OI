#include <iostream>
#include <vector>
#include <queue>

#define int long long
#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e5 + 10;
const int mod = 998244353;

int n, res, top;
int a[N], c[N], dp[N], q[N << 4];
bool vis[N];

inline void solve()
{
	cin >> n;
	rep (i, 1, n) cin >> a[i];
	rep (i, 2, n) dp[i] = 0;
	dp[a[1]] = 1;
	rep (i, 2, n)
	{
		rep (j, 1, i - 1) if (a[j] < a[i])
		{
			while (top && a[j] > q[top]) top--;
			q[++top] = a[j];
		}
		while (top) dp[a[i]] = (dp[a[i]] + dp[q[top]]) % mod, top--;
		if (!dp[a[i]]) dp[a[i]] = 1;
	}
	int res = 0;
	rep (i, 1, n)
	{
		while (top && a[i] > q[top]) top--;
		q[++top] = a[i];
	}
	while (top) res = (res + dp[q[top]]) % mod, top--;
	cout << res << endl;
}

signed main()
{
	file("subseq");

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}