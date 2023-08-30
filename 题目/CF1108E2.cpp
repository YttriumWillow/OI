#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define pb push_back

using namespace std;

const int N = 1e5 + 10;

int n, m, a[N];
int l[N], r[N];
int res, pos, cnt;
vector<int> segl[N];
vector<int> segr[N];

struct Node { int l, r, min, max, add; };

Node t[N << 2];

#define ls (p << 1)
#define rs (p << 1 | 1)

inline void pushup(int p)
{
	t[p].min = min(t[ls].min, t[rs].min);
	t[p].max = max(t[ls].max, t[rs].max);
}

inline void pushdown(int p)
{
	if (t[p].add)
	{
		t[ls].min += t[p].add; t[ls].max += t[p].add;
		t[rs].min += t[p].add; t[rs].max += t[p].add;
		t[ls].add += t[p].add; t[rs].add += t[p].add;
		t[p].add = 0;
	}
}

inline void build(int p, int l, int r)
{
	t[p].l = l, t[p].r = r;
	if (l == r)
	{
		t[p].min = t[p].max = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}

inline void modify(int p, int l, int r, int v)
{
	if (l <= t[p].l && t[p].r <= r)
	{
		t[p].min += v; t[p].max += v;
		t[p].add += v;
		return;
	}
	pushdown(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if (l <= mid) modify(ls, l, r, v);
	if (mid <  r) modify(rs, l, r, v);
	pushup(p);
}

#define query(p) (t[p].max - t[p].min)

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	build(1, 1, n); 

	for (int i = 1; i <= m; ++i)
	{
		cin >> l[i] >> r[i];
		segl[ l[i] ].pb( r[i] );
		segr[ r[i] ].pb( l[i] );
		modify(1, l[i], r[i], -1);
	}

	for (int i = 1; i <= n; ++i)
	{
		for (auto rp : segl[i])
			modify(1, i, rp, 1);
		if (query(1) > res)
			res = query(1), pos = i;
		for (auto lp : segr[i])
			modify(1, lp, i, -1);
	}

	for (int i = 1; i <= m; ++i)
		if (l[i] > pos || r[i] < pos) ++cnt;

	cout << res << endl << cnt << endl;

	for (int i = 1; i <= m; ++i)
		if (l[i] > pos || r[i] < pos)
			cout << i << ' ';

	return 0;
}