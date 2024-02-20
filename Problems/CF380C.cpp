// Problem:      Sereja and Brackets
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/CF380C
// Memory Limit: 250 MB
// Time Limit:   1000 ms
// Created Time: 2023-08-16 19:51:55 

#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define Pii pair<int, int>
#define Lb first
#define Rb second

using namespace std;

const int N = 1e6 + 10;

int n, m;
string s;

struct Node { int l, r, L, R; };

Node t[N << 2];

#define ls (p << 1)
#define rs (p << 1 | 1)

inline void pushup(int p)
{ 
	int mix = min(t[ls].L, t[rs].R);
	t[p].L = t[ls].L + t[rs].L - mix;
	t[p].R = t[ls].R + t[rs].R - mix;
}

inline void build(int p, int l, int r)
{
	t[p].l = l; t[p].r = r;
	if (l == r)
	{
		if (s[l] == '(') t[p].L = 1;
		if (s[r] == ')') t[p].R = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}

inline Pii query(int p, int l, int r)
{
	if (l <= t[p].l && t[p].r <= r)
		return { t[p].L, t[p].R };
	int mid = (t[p].l + t[p].r) >> 1;
	if (l <= mid && !(mid < r)) return query(ls, l, r);
	if (!(l <= mid) && mid < r) return query(rs, l, r);
	Pii lp = query(ls, l, r);
	Pii	rp = query(rs, l, r);
	int mix = min(lp.Lb, rp.Rb);
	return { lp.Lb + rp.Lb - mix, lp.Rb + rp.Rb - mix };
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> s;
	n = s.size(); s = '#' + s;
	
	build(1, 1, n);
	
	cerr << "faq" << endl;
	
	cin >> m;
	
	for (int i = 1, l, r; i <= m; ++i)
	{
		cin >> l >> r;
		Pii res = query(1, l, r);
		cout << (r - l + 1) - res.Lb - res.Rb << endl;
	}
	
	return 0;
}