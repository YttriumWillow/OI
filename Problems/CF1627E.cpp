#pragma GCC optimize(2)

#include <iostream>
#include <vector>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~")

using namespace std;

const int N = 2e5 + 10;
const i64 inf = 0x3f3f3f3f3f3f3f3f;

#define y first
#define idx second
#define fir first
#define sec second
#define pb push_back
#define Pii pair<int, int>

int n, m, k, cnt;
i64 p[N], dp[N];
vector<Pii> flr[N];
Pii trs[N];

template<typename Tp>
inline void upd(Tp& p, Tp q) { p = min(p, q); }

inline void clear()
{
	cnt = 0;
	for (int i = 1; i <= n; ++i) flr[i].clear();
}

inline void solve()
{

	cin >> n >> m >> k; clear();

	for (int i = 1; i <= n; ++i)
		cin >> p[i];

	flr[1].pb({ 1, ++cnt });

	for (int i = 1; i <= k; ++i)
	{
		static int a, b, c, d, w;
		cin >> a >> b >> c >> d >> w;
		flr[a].pb({ b, ++cnt });
		flr[c].pb({ d, ++cnt });
		trs[cnt - 1] = { cnt, w };
	}

	flr[n].pb({ m, ++cnt });
	fill(dp, dp + cnt + 5, inf);
	dp[1] = 0;

	for (int i = 1; i <= n; ++i)
	{
		sort(flr[i].begin(), flr[i].end()); 

		for (int j = 1; j < (int)flr[i].size(); ++j)
			upd(dp[ flr[i][j].idx ], dp[ flr[i][j - 1].idx ] + abs( flr[i][j].fir - flr[i][j - 1].fir ) * p[i]);

		for (int j = flr[i].size() - 1; j > 0; --j)
			upd(dp[ flr[i][j - 1].idx ], dp[ flr[i][j].idx ] + abs( flr[i][j].fir - flr[i][j - 1].fir ) * p[i]);

		for (int j = 0; j < (int)flr[i].size(); ++j)
			if (dp[ flr[i][j].idx ] != inf && trs[ flr[i][j].idx ].fir)
				upd(dp[ trs[ flr[i][j].idx ].fir ], dp[ flr[i][j].idx ] - trs[ flr[i][j].idx ].sec);
	}

	if (dp[cnt] != inf) cout << dp[cnt] << endl;
	else cout << "NO ESCAPE" << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();
	return 0;
}