#include <iostream>
#include <cstring>
#include <algorithm>

#define i64 long long
#define ull unsigned long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)
#define v first
#define id second
#define State pair<ull, int>

using namespace std;

const int N = 1e5 + 10;
const int M = 30;
const int V = 1 << 26;

int n, m;
ull a[N][M], b[N];
ull sum[V];
State st[V];

// inline void upd(ull& x, ull y) { x = min(x, y); }

int main()
{
	file("buy");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	rep (i, 1, n) rep (j, 1, m)
		cin >> a[i][j];
	rep (i, 1, m)
		cin >> b[i];

	rep (i, 1, n)
	{
		rep (j, 1, m) st[j] = { a[i][j], j };
		sort(st + 1, st + m + 1);
		ull S = 0;
		rep (j, 1, m)
		{
			sum[S] += st[j].v;
			S |= (1ull << (st[j].id - 1));
			sum[S] -= st[j].v;
		}
	}

	rep (i, 1, m) rep (S, 0, (1ull << m) - 1)
	{
		if (S & (1ull << (i - 1)))
			sum[S] += sum[S ^ (1ull << (i - 1))];
	}

	reverse(sum, sum + (1 << m));

	ull res = 0x3f3f3f3f3f3f3f3fll;
	rep (i, 1, (1 << m) - 1)
	{
		ull cnt = 0;
		rep (j, 1, m)
			if (i & (1ll << (j - 1)))
				cnt += b[j];
		res = min(res, cnt + sum[i]);
	}

	cout << res << endl;

	return 0;
}