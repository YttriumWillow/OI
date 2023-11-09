#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 802;
const int V = 17;
const int mod = 1e9 + 7;

int n, m, k, res;
int g[N][N];
int f[N][N][V][2];

inline void upd(int &x, int y) { x = (x + y) % mod; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k; ++k;

	rep (i, 1, n) rep (j, 1, m)
	{
		cin >> g[i][j];
		f[i][j][g[i][j] % k][0] = 1;
	}

	rep (i, 1, n) rep (j, 1, m) rep (d, 0, k)
	{
		upd(f[i][j][d][0], f[i - 1][j][(d - g[i][j] + k) % k][1]);
		upd(f[i][j][d][0], f[i][j - 1][(d - g[i][j] + k) % k][1]);
		upd(f[i][j][d][1], f[i - 1][j][(d + g[i][j]) % k][0]);
		upd(f[i][j][d][1], f[i][j - 1][(d + g[i][j]) % k][0]);
	}

	rep (i, 1, n) rep (j, 1, m)
		upd(res, f[i][j][0][1]);

	cout << res << endl;

	return 0;
}