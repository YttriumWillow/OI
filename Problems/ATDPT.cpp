#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 3e3 + 10;
const int mod = 1e9 + 7;

int n, res; string s;
int sum[N], f[2][N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> s; s = "##" + s;

	f[1][1] = 1;

	for (int i = 2; i <= n; ++i, sum[0] = 0)
	{
		for (int j = 1; j < i; ++j)
			sum[j] = (sum[j - 1] + f[(i & 1) ^ 1][j]) % mod;
		for (int j = 1; j <= i; ++j)
			f[i & 1][j] = ( (s[i] == '<' ? sum[j - 1] : sum[i - 1] - sum[j - 1]) % mod + mod ) % mod;
	}

	for (int i = 1; i <= n; ++i)
		res = (res + f[n & 1][i]) % mod;

	cout << res << endl;

	return 0;
}