#include <bits/stdc++.h>
#define qwq printf("fzy_qwq\n");
#define reg register
#define _read =read()
using namespace std;
int n, m, l, r, k;
int stbg[100010][17], stsl[21][5];
int a[2000010];
int Log2[2000010];
inline int read()
{
	int x = 0, sgn = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
	return x * sgn;
}
void init()
{
	for (reg int i = 2; i <= n; i++)
		Log2[i] = Log2[i >> 1] + 1;
	int limit = n / Log2[n];
	for (reg int k = 0; k < limit; k++)
	{
		int runup = min( (k + 1) * Log2[n], n );
		for (reg int j = 1; j < 5; j++)
			for (reg int i = k * Log2[n]; i + (1 << j) - 1 < runup; i++)
				stsl[i][j] = min(stsl[i][j - 1], stsl[i + (1 << (j - 1))][j - 1]);
		stbg[k] = min(st[l][k], st[r - (1 << k) + 1][k])
	}
}
int main()
{
	n _read; m _read;
	for (reg int i = 0; i < n; i++)
		a[i] _read;
	// st table
	for (reg int j = 1; j < 21; j++)
		for (reg int i = 1; i + (1 << j) - 1 <= n; i++)
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	for (reg int i = 1; i <= n; i++)
	{
		if (i == 1) { printf("0\n"); continue; }
		l = max(1, i - m); r = i - 1;
		k = log2(r - l + 1);
		printf("%d\n", min(st[l][k], st[r - (1 << k) + 1][k]));
	}

	return 0;
}