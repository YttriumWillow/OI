// Problem:      GSS3 - Can you answer these queries III
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/SP1716
// Memory Limit: 1 MB
// Time Limit:   330000 ms
// Created Time: 2023-08-17 11:04:19 

#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5e4 + 10;

int n, q;
int a[N];

struct Node { int l, r, sum, L, R, v; };

Node t[N << 2];

#define ls (p << 1)
#define rs (p << 1 | 1)

inline void pushup(int p)
{
	t[p].sum = t[ls].sum + t[rs].sum;
	t[p].L = max(t[ls].L, t[ls].sum + t[rs].L);
	t[p].R = max(t[rs].R, t[rs].sum + t[ls].R);
	t[p].v = max({ t[ls].R + t[rs].L, t[ls].v, t[rs].v });
}

inline void build(int p, int l, int r)
{
	t[p].l = l; t[p].r = r;
	if (l == r)
	{
		t[p].L = t[p].R = t[p].v = t[p].sum = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}

inline void modify(int p, int x, int k)
{
	if (t[p].l == t[p].r)
	{
		t[p].L = t[p].R = t[p].v = t[p].sum = k;
		return;
	}
	int mid = (t[p].l + t[p].r) >> 1;
	if (x <= mid) modify(ls, x, k);
	if (mid  < x) modify(rs, x, k);
	pushup(p);
}

inline Node query(int p, int l, int r)
{
	if (l <= t[p].l && t[p].r <= r)
		return t[p];
	int mid = (t[p].l + t[p].r) >> 1;
	if (r <= mid) return query(ls, l, r);
	if (mid <  l) return query(rs, l, r);
	Node ln = query(ls, l, mid), rn = query(rs, mid + 1, r);
	return {
		l, r,
		ln.sum + rn.sum,
		max(ln.L, ln.sum + rn.L),
		max(rn.R, rn.sum + ln.R),
		max({ ln.R + rn.L, ln.v, rn.v })
	};
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> q;
	build(1, 1, n);
	for (int i = 1, opt, l, r; i <= n; ++i)
	{
		cin >> opt >> l >> r;
		if (!opt) modify(1, l, r);
		else      cout << query(1, l, r).v << endl;
	}
	return 0;
}