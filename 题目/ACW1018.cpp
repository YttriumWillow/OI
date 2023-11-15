#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 110;

int n;
int a[N][N];
int f[N][N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	rep (i, 1, n) rep (j, 1, n)
		cin >> a[i][j];

	rep (i, 1, n) rep (j, 1, n)
		f[i][j] = min(f[i][j], min(f[i - 1][j], f[i][j - 1]) + a[i][j]);

	cout << f[n][n] << endl;

	return 0;
}