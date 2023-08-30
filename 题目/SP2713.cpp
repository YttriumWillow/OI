// Problem:      P4145 上帝造题的七分钟 2 / 花神游历各国
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4145
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-04 20:07:43 

#include <iostream>

#include <cmath>

#define i64 long long
#define reg register
#define bel(p) ((p - 1) / blk + 1)
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, k, l, r, T;
int blk, tot;
int lft[330], rgt[330];
int tag[330];
i64 sum[330];
i64 a[100010];

inline void build(int n)
{
	blk = (int)sqrt(n);
	tot = n / blk; if (n % blk) ++tot;
    for (reg int i = 1; i <= tot; ++i)
    {
        lft[i] = (i - 1) * blk + 1;
        rgt[i] = i * blk;
    } rgt[tot] = n;
    for (reg int i = 1; i <= n; ++i)
    	sum[bel(i)] += a[i];
}

inline void update(int p) { tag[p] = (rgt[p] - lft[p] + 1) == sum[p]; }

inline void modify(int l, int r)
{
	int L = bel(l);
	int R = bel(r);
	if (L == R)
	{
		if (tag[L]) return;
		for (reg int i = l; i <= r; ++i)
		{
			sum[L] -= a[i];
			a[i] = (i64)sqrt(a[i]);
			sum[L] += a[i];
		}
		update(L);
		return;
	}
	if (!tag[L])
	{
		for (reg int i = l; i <= rgt[L]; ++i)
		{
			sum[L] -= a[i];
			a[i] = (i64)sqrt(a[i]);
			sum[L] += a[i];
		}
	}
	if (!tag[R])
	{
		for (reg int i = lft[R]; i <= r; ++i)
		{
			sum[R] -= a[i];
			a[i] = (i64)sqrt(a[i]);
			sum[R] += a[i];
		}
	}
	update(L); update(R);
	for (reg int now = L + 1; now < R; ++now)
	{
		if (tag[now]) continue;
		for (reg int i = lft[now]; i <= rgt[now]; ++i)
		{
			sum[now] -= a[i];
			a[i] = (i64)sqrt(a[i]);
			sum[now] += a[i];
		}
		update(now);
	}
}

inline i64 query(int l, int r)
{
	int L = bel(l);
	int R = bel(r);
	i64 res = 0;
	if (L == R)
	{
		for (reg int i = l; i <= r; ++i)
			res += a[i];
		return res;
	}
	for (reg int i = l; i <= rgt[L]; ++i)
		res += a[i];
	for (reg int i = lft[R]; i <= r; ++i)
		res += a[i];
	for (reg int i = L + 1; i < R; ++i)
		res += sum[i];
	return res;
}

inline void solve()
{
	
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i];
	build(n);
	cin >> m;
	
	cout << "Case #" << T << ":" << endl;
	while (m--)
	{
		cin >> k >> l >> r; if (l > r) swap(l, r);
		if (!k) modify(l, r);
		else cout << query(l, r) << endl;
	}
	fill(sum + 1, sum + tot + 1, 0);
	fill(tag + 1, tag + tot + 1, 0);
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (cin >> n && n) ++T, solve();
	return 0;
}

//9528
