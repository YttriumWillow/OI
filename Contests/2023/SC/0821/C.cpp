#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define pb push_back

#define sqr(x) ((x) * (x))

using namespace std;

i64 k, l, r, ans;

inline i64 calc(i64 x)
{
	i64 res = 0;
	while (x) res += sqr(x % 10ll), x /= 10ll;
	return res;
}

inline void solve()
{
	ans = 0;
	cin >> k >> l >> r;
	for (i64 i = 1; i <= 1458; ++i)
	{
		i64 x = i;

		if(x > r / k) break;
		if(x * k < l) continue;

		int sum = calc(x * k);
		if (sum == x) ++ans;
	}
	cout << ans << endl;
}

int main()
{
	freopen("standard.in", "r", stdin);
	freopen("standard.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}