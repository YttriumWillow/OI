// Problem:       Sasha and Array
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/CF718C
// Memory Limit:  250 MB
// Time Limit:    5000 ms
// Created Time:  2023-07-27 16:53:19 

#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;
const int mod = 1e9 + 7;

int n, m;
int a[N];

struct Matrix
{
	int m[2][2] = { 0 };
	inline void clear() { memset(m, 0, sizeof m); }
	inline void idt() { for (int i = 0; i < 2; ++i) m[i][i] = 1; }
	friend Matrix operator * (const Matrix& a, const Matrix& b)
	{
		static Matrix res; res.clear();
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				for (int k = 0; k < 2; ++k)
					res.m[i][j] = (res.m[i][j] + 1ll * a.m[i][k] * b.m[k][j] % mod) % mod;
		return res;			
	}
	friend Matrix operator + (const Matrix& a, const Matrix& b)
	{
		static Matrix res; res.clear();
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				res.m[i][j] = (a.m[i][j] + b.m[i][j]) % mod;
		return res;
	}
};

inline void fpow(Matrix& a, int k)
{
	static Matrix t;
	t.m[0][0] = 0;
	t.m[0][1] = t.m[1][0] = t.m[1][1] = 1;
	for (; k; k >>= 1)
	{
		if (k & 1) a = a * t;
		t = t * t;
	}
}

struct Node
{
	int l, r;
	Matrix val, add;
} t[N << 2];

#define ls (p << 1)
#define rs (p << 1 | 1)
#define pushup(p) t[p].val = t[ls].val + t[rs].val;

inline void pushdown(int p)
{
	t[ls].val = t[ls].val * t[p].add;
	t[ls].add = t[ls].add * t[p].add;
	
	t[rs].val = t[rs].val * t[p].add;
	t[rs].add = t[rs].add * t[p].add;
	
	t[p].add.m[0][0] = t[p].add.m[1][1] = 1;
	t[p].add.m[0][1] = t[p].add.m[1][0] = 0;
}

inline void build(int p, int l, int r)
{
	t[p].l = l, t[p].r = r;
	t[p].add.m[0][0] = t[p].add.m[1][1] = 1;
	t[p].add.m[0][1] = t[p].add.m[1][0] = 0;
	if (l == r)
	{
		t[p].val.m[0][1] = 1;
		t[p].val.m[0][0] = t[p].val.m[1][0] = t[p].val.m[1][1] = 0;
		fpow(t[p].val, a[l]);
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}

inline void modify(int p, int l, int r, int k)
{
	if (l <= t[p].l && t[p].r <= r)
	{
		fpow(t[p].val, k);
		fpow(t[p].add, k);
		return;
	}
	pushdown(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if (l <= mid) modify(ls, l, r, k);
	if (mid  < r) modify(rs, l, r, k);
	pushup(p);
}

inline int query(int p, int l, int r)
{
	if (l <= t[p].l && t[p].r <= r)
	{ return t[p].val.m[0][0]; }
	pushdown(p);
	int mid = (t[p].l + t[p].r) >> 1, res = 0;
	if (l <= mid) res = (res + query(ls, l, r)) % mod;
	if (mid  < r) res = (res + query(rs, l, r)) % mod;
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	build(1, 1, n);
	for (int i = 1, opt, l, r, x; i <= m; ++i)
	{
		cin >> opt;
		if (opt == 1)
		{
			cin >> l >> r >> x;
			modify(1, l, r, x);
		}
		if (opt == 2)
		{
			cin >> l >> r;
			cout << query(1, l, r) << endl;
		}
	}
	return 0;
}
// 1 1 2 1 1
// 1 1 1 1 1 f
// 1 3 4 3 1
// 1 2 3 2 1 f 