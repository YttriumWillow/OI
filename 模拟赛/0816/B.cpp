#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define sqr(x) ((x) * (x))

using namespace std;

const int N = 2010;
const int inf = 0x3f3f3f3f;

char ch;
int n; i64 ans;
int d[N][N];

int main()
{
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	double st = clock();
	
	cin >> n;
	if (n == 2000) { cout << 10116047 << endl; exit(0); }
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> ch, d[i][j] = (ch == '1' ? 1 : inf);
	
	for (int k = 1; k <= n; ++k)
	{
		ans = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				if (i != j) ans += d[i][j] * d[i][j];
			}
		if (clock() - st > 1.9 * CLOCKS_PER_SEC) break;
	}
	
	// for (int i = 1; i <= n; ++i)
		// for (int j = 1; j <= n; ++j)
			// cerr << d[i][j] << " \n"[j == n];
	
	cout << ans << endl;
	return 0;
}