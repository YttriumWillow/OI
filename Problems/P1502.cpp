#include <iostream>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e5 + 10;

i64 n, w, h, xx, yx, lx;
i64 len, tot, res;
i64 x[N << 1];

struct ScanL
{
	i64 l, r, h, v;
	friend bool operator < (const ScanL& A, const ScanL& B)
		{ return (A.h ^ B.h) ? (A.h < B.h) : (A.v > B.v); }
} l[N << 1];

struct SegTree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
	struct Node { int l, r; i64 Max, tag; } t[N << 2];
	inline void pushup(int p) { auto& T = t[p]; T.Max = max(t[ls].Max, t[rs].Max); }
	inline void pushdown(int p)
	{
		auto& T = t[p];
		if (T.tag)
		{
			t[ls].Max += T.tag; t[rs].Max += T.tag;
			t[ls].tag += T.tag; t[rs].tag += T.tag;
			T.tag = 0;
		}
	}
	inline void build(int p, int l, int r)
	{
		auto& T = t[p]; T.l = l; T.r = r;
		T.Max = T.tag = 0;
		if (l == r) { return; }
		int mid = (l + r) >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
	}
	inline void modify(int p, int l, int r, int v)
	{
		auto& T = t[p];
		if (l <= T.l and T.r <= r)
		{ T.Max += v; T.tag += v; return; }
		pushdown(p);
		int mid = (T.l + T.r) >> 1;
		if (l <= mid) modify(ls, l, r, v);
		if (mid  < r) modify(rs, l, r, v);
		pushup(p);
	}
	inline i64 top() { return t[1].Max; }
	inline void clear(int i, int l, int r) { build(i, l, r); }
} SGT;

inline void solve()
{
	cin >> n >> w >> h;
	rep (i, 1, n)
	{
		cin >> xx >> yx >> lx;
		x[++tot] = yx; 		  l[tot] = { yx, yx + h - 1, xx, lx };
		x[++tot] = yx + h - 1; l[tot] = { yx, yx + h - 1, xx + w - 1, -lx };
	}
	sort(x + 1, x + tot + 1);
	sort(l + 1, l + tot + 1);
	len = unique(x + 1, x + tot + 1) - x - 1, res = 0;
	SGT.build(1, 1, len - 1);
	rep (i, 1, tot)
	{
		i64 L = lower_bound(x + 1, x + len + 1, l[i].l) - x - 1;
		i64 R = lower_bound(x + 1, x + len + 1, l[i].r) - x - 1;
		SGT.modify(1, L, R, l[i].v);
		res = max(res, SGT.top());
	}
	cout << res << endl;
}

inline void clear()
{
	SGT.clear(1, 1, len - 1); tot = 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve(), clear();
	return 0;
}