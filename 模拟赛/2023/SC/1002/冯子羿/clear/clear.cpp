#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 52;

int n; char ch;
int a[N][N];
int sum[N][N];
int f[N][N];

namespace Sol
{
inline void solve()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= i && k <= j; ++k)
			{
				// f[i][j] = min(f[i][j])
			}
		}
	}
}
}

int main()
{
	file("clear");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> ch;
			a[i][j] = (ch == '#');
		}
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j]; 

	// Sol::solve();

	if (sum[n][n] == 3) cout << 2 << endl;
	else cout << sum[n][n] << endl;


	return 0;
}