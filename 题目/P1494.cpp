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

const int N = 5e4 + 10;
const int C = 5e4 + 10;
const int Q = 5e4 + 10;

int n, m, a[N];
int buc[C]; i64 cnt;
pair<i64, i64> res[Q];

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
	cnt -= sqr(buc[a[x]]);
	++buc[a[x]];
	cnt += sqr(buc[a[x]]);
}
inline void del(int x)
{
	cnt -= sqr(buc[a[x]]);
	--buc[a[x]];
	cnt += sqr(buc[a[x]]);
}
inline void solve()
{
	int l = 1, r = 0;
	for (int i = 1; i <= m; ++i)
	{
		while (r < qry[i].r) add(++r);
		while (l > qry[i].l) add(--l);
		while (l < qry[i].l) del(l++);
		while (r > qry[i].r) del(r--);

		if (qry[i].l == qry[i].r) { res[qry[i].id] = { 0, 1 }; continue; }
		res[qry[i].id].fir = cnt - (qry[i].r - qry[i].l + 1);
		res[qry[i].id].sec = 1ll * (qry[i].r - qry[i].l + 1) * (qry[i].r - qry[i].l);
		i64 g = __gcd(res[qry[i].id].fir, res[qry[i].id].sec);
		res[qry[i].id].fir /= g;
		res[qry[i].id].sec /= g;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m; init(n);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i)
	{
		cin >> qry[i].l >> qry[i].r;
		qry[i].id = i;
	}

	sort(qry + 1, qry + m + 1);
	solve();

	for (int i = 1; i <= m; ++i)
		cout << res[i].first << '/' << res[i].second << endl;
	return 0;
}