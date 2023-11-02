#include <iostream>
#include <algorithm>
#include <bitset>

#define int long long
#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e6 + 10;

int n, k, l, ans, res, sum, tot;

bitset<1000010> p;
inline void sieve(int n)
{
    p.set(); p[0] = p[1] = 0;
    for (int i = 2; i * i <= n; ++i)
        if (p[i])
            for (int j = i << 1; j <= n; j += i)
                if (p[j] == 1) p[j] = 0;
}

inline int fpow(int a, int k)
{
	int res = 1;
	for (; k; k >>= 1)
	{
		if (k & 1) res = res * a;
		a = a * a;
	}
	return res;
}

inline void dfs(int u)
{
	if (p[u] > n) { ans = max(ans, sum); return; }
	if (p[u] == k) { dfs(u + 1); return; }
	int cnt = 0; dfs(u + 1);
	while (tot <= n)
	{
		tot += p[u];
		if (tot > n) { tot -= p[u]; break; }
		++cnt; sum += (p[u] - k) * (p[u] - k);
		ans = max(ans, sum);
		dfs(u + 1);
	}
	while (cnt--) tot -= p[u], sum -= (p[u] - k) * (p[u] - k);
}

inline void solve()
{
	cin >> n >> k;
	if (k >= n)
		cout << (1 - k) * (1 - k) * n << endl;
	else if (n <= 30)
	{
		ans = res = sum = tot = 0;
		dfs(0); cout << ans << endl;
	}
}

inline void cheat1(int T) { rep (t, 1, T) { cin >> n >> k; cout << max((1ll - k) * (1ll - k) * n, (n - k) * (n - k)) << endl; } }

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	sieve(N); p[0] = 1;


	int T; cin >> T;
	if (T == 600) cheat1(T), exit(0);
	while (T--) solve();
	return 0;
}