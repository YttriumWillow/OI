#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 22;
const int mod = 1e9 + 7;

int n, m;
int g[N][N];
int f[1 << N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 1, n) rep (j, 1, n)
		cin >> g[i][j];

	f[0] = 1;
	rep (S, 1, (1 << n) - 1)
	{
		int cnt = __builtin_popcount(S);
		rep (i, 1, n)
			if (g[cnt][i] && S >> (i - 1) & 1)
				f[S] = (f[S] + f[S - (1 << (i - 1))]) % mod;
	}

	cout << f[(1 << n) - 1] << endl;
	return 0;
}