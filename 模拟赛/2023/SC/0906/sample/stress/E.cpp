#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e3 + 10;
const i64 mod = 1e9 + 7;

int n, m, a[N], tick;

struct Node
{
	int l, r; i64 v;
	i64 add, mul; int rpd = 0;
	i64 siz() { return r - l + 1; }
} t[N << 2];

#define ls (p << 1)
#define rs (p << 1 | 1)

inline void pushup(int p) { t[p].v = (t[ls].v + t[rs].v) % mod; }

inline void pushrpd(int p)
{
	t[ls].rpd = max(t[ls].rpd, t[p].rpd);
	t[rs].rpd = max(t[rs].rpd, t[p].rpd);
}

inline void pushdown(i64 p)
{
	Node& T = t[p];

	t[ls].v = (t[ls].v * T.mul + (T.add * t[ls].siz()) % mod) % mod;
	t[rs].v = (t[rs].v * T.mul + (T.add * t[rs].siz()) % mod) % mod;
		
	t[ls].mul = (t[ls].mul * T.mul % mod) % mod;
	t[rs].mul = (t[rs].mul * T.mul % mod) % mod;
		
	t[ls].add = ((t[ls].add * T.mul) % mod + T.add) % mod;
	t[rs].add = ((t[rs].add * T.mul) % mod + T.add) % mod;
	
	pushrpd(p);

	T.mul = 1;
	T.add = 0;
}

inline void build(int p, int l, int r)
{
	Node& T = t[p];
	T.l = l; T.r = r; T.mul = 1;
	if (l == r) { T.v = a[l]; return;  }
	i64 mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}

inline void add(int p, int l, int r, int k)
{
	Node& T = t[p];
	if (l <= T.l && T.r <= r)
	{
		if (tick <= t[p].rpd) return;
		T.v = (T.v + k * T.siz() % mod) % mod;
		T.add = (T.add + k) % mod;
		return;
	}
	pushdown(p);
	pushup(p);
	i64 mid = (T.l + T.r) >> 1;
	if (l <= mid) add(ls, l, r, k);
	if (mid <  r) add(rs, l, r, k);
	pushup(p);
}

inline void mul(int p, int l, int r, int k)
{
	Node& T = t[p];
	if (l <= T.l && T.r <= r)
	{
		if (tick <= t[p].rpd) return;
		T.v = (T.v * k) % mod;
		T.mul = (T.mul * k) % mod;
		T.add = (T.add * k) % mod;
		return;
	}
	pushdown(p);
	pushup(p);
	i64 mid = (T.l + T.r) >> 1;
	if (l <= mid) mul(ls, l, r, k);
	if (mid <  r) mul(rs, l, r, k);
	pushup(p);
}

inline i64 query(int p, int l, int r)
{
	Node& T = t[p];
	if (l <= T.l && T.r <= r)
		return T.v;
	pushdown(p);
	int mid = (T.l + T.r) >> 1;
	i64 ans = 0;
	if (l <= mid) ans = (ans + query(ls, l, r) % mod) % mod;
	if (mid <  r) ans = (ans + query(rs, l, r) % mod) % mod;
	return ans % mod;
}

inline void rpe(int p, int l, int r, int k)
{
	Node& T = t[p];
	if (l <= T.l && T.r <= r)
	{
		T.rpd = max(T.rpd, tick + k);
		return;
	}
	// pushdown(p);
	int mid = (T.l + T.r) >> 1;
	if (l <= mid) rpe(ls, l, r, k);
	if (mid <  r) rpe(rs, l, r, k);
	// pushup(p);
}

int main()
{
	// freopen("stress.in", "r", stdin);
	// freopen("stress.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	build(1, 1, n);

	int opt, l, r, x;
	for (tick = 1; tick <= m; ++tick)
	{
		cin >> opt >> l >> r;
		if (opt == 1) cin >> x, add(1, l, r, x);
		if (opt == 2) cin >> x, mul(1, l, r, x);
		if (opt == 3) cin >> x, rpe(1, l, r, x);
		if (opt == 4) cout << query(1, l, r) << endl;
	}
	return 0;
}