// Problem:       Permutation
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/CF452F
// Memory Limit:  250 MB
// Time Limit:    1000 ms
// Created Time:  2023-07-20 12:32:12 

// Problem:       P2757 [国家集训队] 等差子序列
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/P2757
// Memory Limit:  512 MB
// Time Limit:    2000 ms
// Created Time:  2023-07-20 09:30:02 

#include <iostream>

#define int long long
#define i64 long long
#define u64 unsigned long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5e5 + 10;
const int mod = 1e9 + 7;

int T, n, a[N];
int bse[N];
inline void init(int n)
{
	bse[0] = 1;
	for (int i = 1; i <= n; ++i)
		bse[i] = (bse[i - 1] * 2ll) % mod;
}

struct Node { int l, r, len, h[2]; } t[N << 2];
#define ls (p << 1)
#define rs (p << 1 | 1)

inline void pushup(int p)
{
	t[p].h[0] = (t[ls].h[0] * bse[t[rs].len] % mod + t[rs].h[0]) % mod;
	t[p].h[1] = (t[rs].h[1] * bse[t[ls].len] % mod + t[ls].h[1]) % mod;
}
inline void build(int p, int l, int r)
{
	t[p].l = l, t[p].r = r;
	if (l == r) { t[p].len = 1, t[p].h[0] = t[p].h[1] = 0; return; }
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	t[p].len = t[ls].len + t[rs].len;
	t[p].h[0] = t[p].h[1] = 0;
}
inline void modify(int p, int x)
{
	if (t[p].l == t[p].r) { t[p].h[0] = t[p].h[1] = 1; return; }
	int mid = (t[p].l + t[p].r) >> 1;
	if (x <= mid) modify(ls, x);
	else		  modify(rs, x);
	pushup(p);
}
inline int query(int p, int l, int r, int k)
{
	if (l <= t[p].l && t[p].r <= r)
		return t[p].h[k];
	int mid = (t[p].l + t[p].r) >> 1;
	int ll = max(mid - max(l, t[p].l) + 1, 0ll);
	int lr = max(min(r, t[p].r) - mid, 0ll);
	int res = 0;
	if (!k)
	{
		if (l <= mid) res += (query(ls, l, r, k) * bse[lr]) % mod;
		if (mid <  r) res += query(rs, l, r, k) % mod;
	}
	else
	{
		if (l <= mid) res += query(ls, l, r, k) % mod;
		if (mid <  r) res += (query(rs, l, r, k) * bse[ll]) % mod;
	}
	return res % mod;
}

inline void solve()
{
	cin >> n; build(1, 1, n);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];	
	bool flg = 0;
	for (int i = 2; i < n; ++i)
	{
		modify(1, a[i - 1]);
		if (a[i] == 1 || a[i] == n) continue;
		int L = min(a[i] - 1, n - a[i]);
		
		// cerr << "m psd " << i << endl;
        if (query(1, a[i] - L, a[i] - 1, 0) != query(1, a[i] + 1, a[i] + L, 1))
		{ cout << "YES" << endl, flg = true; break; }
		
		// cerr << "q psd " << i << endl;
	}
    if (!flg) cout << "NO" << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	init(N - 5);
	solve();
	return 0;
}