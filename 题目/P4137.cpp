#include <iostream>
#include <cmath>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e5 + 10;
const int C = 2e5 + 10;
const int Q = 2e5 + 10;

int n, m, k, a[N];
int cnt, buc[C];
int res[Q];

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
	if (!buc[a[x]]) cnt = min(cnt, )
	cnt += 2 * buc[a[x]] + 1;
	++buc[a[x]];
}
inline void del(int x)
{
	cnt -= 2 * buc[a[x]] - 1;
	--buc[a[x]];
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
		res[qry[i].id] = cnt;
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
		cout << res[i] << endl;
	return 0;
}