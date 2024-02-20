#include <iostream>
#include <algorithm>
#include <cmath>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5e4 + 10;
const int Q = 2e5 + 10;

int n, m, M, a[N];
int blk, tot;
int bel[N], bucL[N], bucR[N];
i64 cnt, res[N];

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
	int l, r, id, d;
	friend bool operator < (const Query& A, const Query& B)
	{ return (bel[A.l] ^ bel[B.l]) ? bel[A.l] < bel[B.l] : ((bel[A.l] & 1) ? A.r < B.r : A.r > B.r); }
} qry[Q];

inline void addL(int x)
{
	cnt -= bucL[a[x]] * bucR[a[x]];
	++bucL[a[x]];
	cnt += bucL[a[x]] * bucR[a[x]];
}

inline void delL(int x)
{
	cnt -= bucL[a[x]] * bucR[a[x]];
	--bucL[a[x]];
	cnt += bucL[a[x]] * bucR[a[x]];
}

inline void addR(int x)
{
	cnt -= bucL[a[x]] * bucR[a[x]];
	++bucR[a[x]];
	cnt += bucL[a[x]] * bucR[a[x]];
}

inline void delR(int x)
{
	cnt -= bucL[a[x]] * bucR[a[x]];
	--bucR[a[x]];
	cnt += bucL[a[x]] * bucR[a[x]];
}

inline void solve()
{
	int l = 0, r = 0;
	for (int i = 1; i <= M; ++i)
	{
		while (l > qry[i].l) delL(l--);
		while (l < qry[i].l) addL(++l);
		while (r > qry[i].r) delR(r--);
		while (r < qry[i].r) addR(++r);

		res[qry[i].id] += 1ll * qry[i].d * cnt;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; init(n);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	cin >> m;
	for (int i = 1; i <= m; ++i)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		qry[++M] = { r1, r2,     i,  1 };
		qry[++M] = { r1, l2 - 1, i, -1 };
		qry[++M] = { l1 - 1, r2, i, -1 };
		qry[++M] = { l1 - 1, l2 - 1, i, 1 };
	}

	for (int i = 1; i <= M; ++i)
		if (qry[i].l > qry[i].r)
			swap(qry[i].l, qry[i].r);

	sort(qry + 1, qry + M + 1); solve();

	for (int i = 1; i <= m; ++i)
		cout << res[i] << endl;
	return 0;
}