#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;

struct Node
{
	int l, r, siz;
	int _0, _1, l0, l1, r0, r1, res0, res1;
	int cvr = -1, rev = 0;
	Node() {}
	Node(int _l, int _r)
	{
		l = _l, r = _r,
		siz = (_r - _l + 1),
		_0 = 0, _1 = 0, 
		l0 = 0, l1 = 0, 
		r0 = 0, r1 = 0, 
		res0 = 0, res1 = 0;
	}
	Node(int _l, int _r, int a, int b, int c, int d, int e, int f, int g, int h)
	{
		l = _l, r = _r, 
		siz = (_r - _l + 1), 
		_0 = a, _1 = b, 
		l0 = c, l1 = d, 
		r0 = e, r1 = f, 
		res0 = g, res1 = h;
	}
	Node(int _l, int _r, int a, int b, int c, int d, int e, int f, int g, int h, int p, int q)
	{
		l = _l, r = _r, 
		siz = (_r - _l + 1), 
		_0 = a, _1 = b, 
		l0 = c, l1 = d, 
		r0 = e, r1 = f, 
		res0 = g, res1 = h;
		cvr()
	}
};

int n, m;
bool a[N];
Node t[N << 2];

#define ls (p << 1)
#define rs (p << 1 | 1)

inline void pushup(int p)
{
	Node& L = t[ls], R = t[rs];
	t[p] = Node(
		t[p].l, t[p].r,
		L._0 + R._0, 							// _0
		L._1 + R._1,							// _1
		(L._1 ? L.l0 : L.l0 + R.l0),			// l0
		(L._0 ? L.l1 : L.l1 + R.l1),			// l1
		(R._1 ? R.r0 : L.r0 + R.r0),			// r0
		(R._0 ? R.r1 : L.r1 + R.r1),			// r1
		max({ L.res0, R.res0, L.r0 + R.l0 }),	// res0
		max({ L.res1, R.res1, L.r1 + R.l1 })	// res1
	);
}

function<void(int)> spread[3] = {
	[](int p)
	{
		t[p].cvr = 0; t[p].rev = 0;
		t[p] = Node(t[p].l, t[p].r, t[p].siz, 0, t[p].siz, 0, t[p].siz, 0, t[p].siz, 0);
	},
	[](int p)
	{
		t[p].cvr = 1; t[p].rev = 0;
		t[p] = Node(t[p].l, t[p].r, 0, t[p].siz, 0, t[p].siz, 0, t[p].siz, 0, t[p].siz);
	},
	[](int p)
	{
		t[p].rev ^= 1;
		t[p] = Node(t[p].l, t[p].r, t[p]._1, t[p]._0, t[p].l1, t[p].l0, t[p].r1, t[p].r0, t[p].res1, t[p].res0);
	}
};

inline void pushdown(int p)
{
	if (t[p].cvr != -1) spread[t[p].cvr](ls), spread[t[p].cvr](rs);
	if (t[p].rev) spread[2](ls), spread[2](rs);
	t[p].cvr = -1; t[p].rev = 0;
}

inline void build(int p, int l, int r)
{
	t[p].l = l, t[p].r = r;
	t[p].siz = (r - l + 1);
	if (l == r)
	{
		int v = a[l];
		t[p] = Node(t[p].l, t[p].r, v ^ 1, v, v ^ 1, v, v ^ 1, v, v ^ 1, v);
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}

inline void modify(int p, int l, int r, int c)
{
	if (l <= t[p].l && t[p].r <= r)
		{ spread[c](p); return; }
	pushdown(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if (l <= mid) modify(ls, l, r, c);
	if (mid <  r) modify(rs, l, r, c);
	pushup(p);
}

inline Node query(int p, int l, int r)
{
	if (l <= t[p].l && t[p].r <= r)
		return t[p];
	pushdown(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if (r <= mid) return query(ls, l, r);
	if (mid <  l) return query(rs, l, r);
	Node L = query(ls, l, r), R = query(rs, l, r);
	return Node(
		t[p].l, t[p].r,
		L._0 + R._0, 							// _0
		L._1 + R._1,							// _1
		(L._1 ? L.l0 : L.l0 + R.l0),			// l0
		(L._0 ? L.l1 : L.l1 + R.l1),			// l1
		(R._1 ? R.r0 : L.r0 + R.r0),			// r0
		(R._0 ? R.r1 : L.r1 + R.r1),			// r1
		max({ L.res0, R.res0, L.r0 + R.l0 }),	// res0
		max({ L.res1, R.res1, L.r1 + R.l1 })	// res1
	);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	build(1, 1, n);

	for (int i = 1, opt, l, r; i <= m; ++i)
	{
		cin >> opt >> l >> r; ++l, ++r;
		
		if (opt <= 2)
			modify(1, l, r, opt);
		else if (opt == 3)
			cout << query(1, l, r)._1 << endl;
		else if (opt == 4)
			cout << query(1, l, r).res1 << endl;
	}
	return 0;
}