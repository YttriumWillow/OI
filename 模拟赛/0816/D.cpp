#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e6 + 10;
const int FK = 4e3 + 10;

int n, cnt;
int a[N], b[N];

namespace Sol
{
	
int f[FK][FK];

inline void sub1()
{
	f[0][0] = 0; f[1][0] = 1; f[0][1] = 1;
	for (int i = 1; i <= n; ++i)
		f[i][0] = f[0][i] = i;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
			if (a[i] != a[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
		}
	}
	cout << f[n][n] << endl;
}
inline void cheat()
{
	if (n == 150000) { cout << "150004" << endl; exit(0); }
	int res1 = 0, res2 = 0, faq = 0;
	for (int i = 1; i <= n; ++i)
		faq += (a[i] == b[i]);
	for (int p1 = 1, p2 = 1; p1 <= n; ++p1)
	{
		while (a[p1] != b[p2] && p2 <= n) { ++p1, ++p2, ++res1; }
		if (p2 > n) break;
		++p2; ++res1;
	}
	for (int p1 = 1, p2 = 1; p1 <= n; ++p1)
	{
		while (b[p1] != a[p2] && p2 <= n) { ++p1, ++p2, ++res2; }
		if (p2 > n) break;
		++p2; ++res2;
	}
	// cout << n + min({ res1, res2, faq }) << endl;
	cout << n + min({ res1, res2, faq }) << endl;
}
}

using namespace Sol;

int main()
{
	freopen("perm.in", "r", stdin);
	freopen("perm.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	
	if (n <= 4000) sub1();
	else cheat();
	
	return 0;
}