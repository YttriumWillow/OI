#include <iostream>

#define int long long
#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 5e3 + 10;
const i64 inf = 0x3f3f3f3f3f3f3f3f;

i64 n, k, A, B;
i64 t[N], f[N][N];

template<typename Tp>
inline void upd(Tp& x, Tp y) { x = min(x, y); }

signed main()
{
	file("songfen");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k >> A >> B;
	rep (i, 1, n) cin >> t[i];

	rep (i, 0, n) rep (j, 1, n + 1) f[i][j] = inf;

	f[0][1] = 0;

	rep (i, 1, n) rep (j, max(1ll, i - k + 1), n)
	{
		if (i >= j) upd( f[i][j + 1], f[i - 1][j] + B * (i - j) + t[i] );
		if (k > i - j + 1) upd( f[i][j], f[i - 1][j] );
		upd( f[i][ min(j + k, n + 1) ], f[i - 1][j] + A );
	}

	cout << f[n][n + 1] << endl;

	return 0;
}