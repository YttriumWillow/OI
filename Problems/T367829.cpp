#include <iostream>
#include <algorithm>
#include <cmath>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e6 + 10;
const int inf = 0x3f3f3f3f;

int n, m; i64 v0, v1;
int a[N], b[N], c[N];

namespace SegTree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
struct Node
{
	int l, r;
	int add, Max;
} t[2][N << 2];

inline void pushup(const int i, int p) { t[i][p].Max = max(t[i][ls].Max, t[i][rs].Max); }
inline void pushdown(const int i, int p)
{
	Node& T = t[i][p];
	if (T.add)
	{
		t[i][ls].Max += T.add; t[i][rs].Max += T.add;
		t[i][ls].add += T.add; t[i][rs].add += T.add;
		T.add = 0;
	}
}

inline void build(const int i, int p, int l, int r)
{
	Node& T = t[i][p]; T.l = l; T.r = r;
	if (l == r) { T.Max = (i & 1) ? c[l] : b[l]; return; }
	int mid = (l + r) >> 1;
	build(i, ls, l, mid);
	build(i, rs, mid + 1, r);
	pushup(i, p);
}

inline void modify(const int i, int p, int l, int r, int v)
{
	Node& T = t[i][p];
	if (l <= T.l and T.r <= r)
	{ T.Max += v; T.add += v; return; }
	pushdown(i, p);
	int mid = (T.l + T.r) >> 1;
	if (l <= mid) modify(i, ls, l, r, v);
	if (mid  < r) modify(i, rs, l, r, v);
	pushup(i, p);
}

inline int query(const int i, int p, int l, int r)
{
	Node& T = t[i][p];
	if (l <= T.l and T.r <= r)
	{ return T.Max; }
	pushdown(i, p);
	int mid = (T.l + T.r) >> 1, res = -inf;
	if (l <= mid) res = max(res, query(i, ls, l, r));
	if (mid  < r) res = max(res, query(i, rs, l, r));
	pushup(i, p); return res;
}
} using namespace SegTree;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	rep (i, 1, n) cin >> a[i];
	rep (i, 1, n - 1) b[i] = a[i] + a[i + 1];
	rep (i, 1, n - 2) c[i] = a[i] + a[i + 1] + a[i + 2];

	build(0, 1, 1, n - 1);
	build(1, 1, 1, n - 2);

	rep (i, 1, m)
	{
		int opt, l, r, x;
		cin >> opt >> l >> r;
		if (opt == 1)
		{
			cin >> x;
			if (l >= 2) 		modify(0, 1, l - 1, l - 1, x);
			if (r + 1 <= n) 	modify(0, 1, r, r, x);
			if (r - l + 1 >= 2) modify(0, 1, l, r - 1, x << 1);

			if (l >= 3) 		modify(1, 1, l - 2, l - 2, x);
			if (l >= 2 and l + 1 <= n)
								modify(1, 1, l - 1, l - 1, x << 1);
			if (r + 2 <= n) 	modify(1, 1, r, r, x);
			if (r + 1 <= n) 	modify(1, 1, r - 1, r - 1, x << 1);
			if (r - l + 1 >= 3) modify(1, 1, l, r - 2, x * 3);
		}
		else
		{
			v0 = query(0, 1, l, r - 1);
			v1 = (r - l + 1 >= 3) ? query(1, 1, l, r - 2) : -inf;

			if (v0 * 3 >= v1 * 2)
			{
				int t = __gcd(abs(v0), 2ll);
				if (!v0)	cout << "0/1" << endl;
				else 		cout << v0 / t << '/' << 2 / t << endl;
			}
			else
			{
				int t = __gcd(abs(v1), 3ll);
				if (!v1)	cout << "0/1" << endl;
				else 		cout << v1 / t << '/' << 3 / t << endl;
			}
		}
	}

	return 0;
}