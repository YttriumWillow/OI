#pragma GCC optimize(2)

#include <iostream>
#include <cmath>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define sqr(x) (1ll * (x) * (x))
#define fir first
#define sec second

using namespace std;

const int N = 1e5 + 1010;
const int C = 1e7 + 10;
const int Q = 1e5 + 1010;

int n, m, k, a[N];
int buc[C];
i64 cnt, res[Q];

int blk, tot, bel[N];

inline void init(int n)
{
	blk = (int)sqrt(n);
	tot = n / blk + !!(n % blk);
	for (int i = 1; i <= tot; ++i)
		for (int j = (i - 1) * blk + 1; j <= i * blk; ++j)
			bel[j] = i;
}

struct Query
{
	int l, r, id;
	friend bool operator < (const Query& _x, const Query& _y)
	{ return (bel[_x.l] ^ bel[_y.l]) ? bel[_x.l] < bel[_y.l] : ((bel[_x.l] & 1) ? _x.r < _y.r : _x.r > _y.r); }
} qry[Q];

inline void add(int x)
{
	cnt += buc[a[x] ^ k];
	++buc[a[x]];
}
inline void del(int x)
{
	--buc[a[x]];
	cnt -= buc[a[x] ^ k];
}

inline void solve()
{
	int l = 1, r = 0;
	for (int i = 1; i <= m; ++i)
	{
		while (l > qry[i].l) add(--l);
		while (l < qry[i].l) del(l++);
		while (r > qry[i].r) del(r--);
		while (r < qry[i].r) add(++r);

		res[qry[i].id] = cnt;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k; init(n);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		a[i] ^= a[i - 1];
	for (int i = 1; i <= m; ++i)
	{
		cin >> qry[i].l >> qry[i].r;
		--qry[i].l; qry[i].id = i;
	}

	sort(qry + 1, qry + m + 1);
	solve();

	for (int i = 1; i <= m; ++i)
		cout << res[i] << endl;
	return 0;
}