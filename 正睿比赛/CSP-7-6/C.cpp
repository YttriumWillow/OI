#include<bits/stdc++.h>
#define ld long double
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N = 3e5 + 5;
int n, m;
ll x[N], y[N], e[N][4], tmp, res0, res1, res2, res3, a, b;
struct SGT
{
	ll sum[N << 2][4];
	void update(int p)
	{
		sum[p][0] = std::max(sum[p << 1][0], sum[p << 1 | 1][0]);
		sum[p][1] = std::max(sum[p << 1][1], sum[p << 1 | 1][1]);
		sum[p][2] = std::max(sum[p << 1][2], sum[p << 1 | 1][2]);
		sum[p][3] = std::max(sum[p << 1][3], sum[p << 1 | 1][3]);
	}
	void build(int p, int l, int r)
	{
		if (l == r)
		{
			sum[p][0] = e[l][0];
			sum[p][1] = e[l][1];
			sum[p][2] = e[l][2];
			sum[p][3] = e[l][3];
			return;
		}
		int mid = l + r >> 1;
		build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
		update(p);
	}
	void inquire(int p, int l, int r, int L, int R)
	{
		if (L <= l && R >= r)
		{
			res0 = std::max(res0, sum[p][0]);
			res1 = std::max(res1, sum[p][1]);
			res2 = std::max(res2, sum[p][2]);
			res3 = std::max(res3, sum[p][3]);
			return;
		}
		if (l >= r) return;
		int mid = l + r >> 1;
		if (L <= mid) inquire(p << 1, l, mid, L, R);
		if (R > mid) inquire(p << 1 | 1, mid + 1, r, L, R);
	}
} t;
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);
	std::cin >> n >> m >> a >> b; tmp = a * a + b * b;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> x[i] >> y[i];
		ll tmp1 = x[i] * a + y[i] * b, tmp2 = -x[i] * b + y[i] * a;
		x[i] = tmp1, y[i] = tmp2;
	}
	for (int i = 1; i <= n; ++i) e[i][0] = x[i] + y[i];
	for (int i = 1; i <= n; ++i) e[i][1] = x[i] - y[i];
	for (int i = 1; i <= n; ++i) e[i][2] = -x[i] + y[i];
	for (int i = 1; i <= n; ++i) e[i][3] = -x[i] - y[i];
	t.build(1, 1, n);
	for (int i = 1, l, r; i <= m; ++i)
	{
		ll p, q;
		std::cin >> l >> r >> p >> q;
		ll tmp1 = p * a + q * b, tmp2 = -p * b + q * a, ans = 0;
		p = tmp1, q = tmp2;
		res0 = res1 = res2 = res3 = -inf;
		t.inquire(1, 1, n, l, r);
		ans = std::max(ans, res0 - p - q);
		ans = std::max(ans, res1 - p + q);
		ans = std::max(ans, res2 + p - q);
		ans = std::max(ans, res3 + p + q);
		ll g = std::__gcd(ans, tmp);
		std::cout << ans / g << '/' << tmp / g << "\n";
	}
	return 0;
}