#include <iostream>

#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

const int N = 1e5 + 10;
const int M = 20;
const int mod = 2027;

int n, m, s[M];
int dp[N];

int main()
{
	// file("C");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		cin >> s[i];
	sort(s + 1, s + m + 1);

	dp[0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m && i - s[j] >= 0; ++j)
		{
			dp[i] = (dp[i] + dp[i - s[j]] * (i - s[j] + 1) % mod) % mod;
		}
	}

	cout << dp[n] << endl;

	return 0;
}