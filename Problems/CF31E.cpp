#include <bits/stdc++.h>

#define i64 long long 
#define u64 unsigned long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 40;

int n; char ch;
int a[N];
u64 f[N][N];
u64 bse[N] = { 1ull };

inline void answer(int i, int v)
{
	if (i > (n << 1)) return;
	if (v && f[i][v] == f[i + 1][v - 1] + bse[v] * a[i])
		{ cout << 'H'; answer(i + 1, v - 1); }
	else
		{ cout << 'M'; answer(i + 1, v); }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= (n << 1); ++i)
		cin >> ch, a[i] = ch - '0';

	for (int i = 1; i <= (n << 1); ++i)
		bse[i] = bse[i - 1] * 10;

	for (int i = (n << 1); i >= 1; --i)
		for (int j = 0; j <= (n << 1) - i + 1; ++j)
		{
			int cb = (n << 1) - i + 1 - j;
			if (j > 0)
				f[i][j] = max(f[i][j], f[i + 1][j - 1] + bse[j] * a[i]);
			if (cb > 0)
				f[i][j] = max(f[i][j], f[i + 1][j] + bse[cb] * a[i]);
		}
	answer(1, n);
	return 0;
}