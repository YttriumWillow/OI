#include <iostream>

#include <cstring>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 21;
const int M = 1e5 + 10;

int n, m, ans;
int p[M], f[N][(1 << 20) + 5];
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s;
		for (int j = 1; j <= m; ++j)
			p[j] = (p[j] << 1) + (s[j - 1] - '0');
	}

	for (int i = 1; i <= m; ++i)
		++f[0][p[i]];

	for (int k = 0; k < n; ++k)
		for (int i = n; i >= 1; --i)
			// for (int i = 1; i <= n; ++i)
			for (int j = 0; j < (1 << n); ++j)
				f[i][j] += f[i - 1][j ^ (1 << k)];

	ans = n * m;
	for (int i = 0; i < (1 << n); ++i)
	{
		int res = 0;
		for (int j = 0; j <= n; ++j)
			res += f[j][i] * min(j, n - j);
		ans = min(ans, res);
	}
	cout << ans << endl;

	return 0;
}