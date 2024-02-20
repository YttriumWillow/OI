#include <iostream>
#include <cstring>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 110;

int r, c;
int a[N][N];
int f[N][N];

inline void solve()
{
	cin >> r >> c;
	rep (i, 1, r) rep (j, 1, c)
		cin >> a[i][j];
	rep (i, 1, r) rep (j, 1, c)
		f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
	cout << f[r][c] << endl;

	memset(f, 0, sizeof f);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();
	return 0;
}