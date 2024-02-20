// Problem:       P3295 [SCOI2016] 萌萌哒
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/P3295
// Memory Limit:  125 MB
// Time Limit:    1000 ms
// Created Time:  2023-07-31 10:24:47 

#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;
const int LOG = 21;
const int mod = 1e9 + 7;

int n, m, ans;
int fa[N][LOG];

inline int find(int x, int k)
{
	return x == fa[x][k] ? x : fa[x][k] = find(fa[x][k], k); 
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m; int lmt = (int)log2(n);
	for (int i = 1; i <= n; ++i)
		for (int k = 0; k <= lmt; ++k)
			fa[i][k] = i;
	for (int i = 1, l1, l2, r1, r2; i <= m; ++i)
	{
		cin >> l1 >> r1 >> l2 >> r2;
		for (int k = lmt; ~k; --k)
			if (l1 + (1 << k) - 1 <= r1)
			{
				int x = find(l1, k);
				int y = find(l2, k);
				if (x != y) fa[x][k] = y;
				
				l1 += 1 << k;
				l2 += 1 << k;
			}
	}
	// cerr << "init suc" << endl;
	for (int k = lmt; k; --k)
	{
		for (int i = 1; i + (1 << k) - 1 <= n; ++i)
		{
			int p = find(i, k);
			
			int x = find(i, k - 1);
			int y = find(p, k - 1);
			if (x != y) fa[x][k - 1] = y;
			
			x = find(i + (1 << (k - 1)), k - 1);
			y = find(p + (1 << (k - 1)), k - 1);
			if (x != y) fa[x][k - 1] = y;
		}
	}
	// cerr << "qwqwqwqwq" << endl;
	for (int i = 1; i <= n; ++i)
		if (fa[i][0] == i)
			ans = !ans ? 9 : ans * 10ll % mod;
	cout << ans << endl;
	return 0;
}