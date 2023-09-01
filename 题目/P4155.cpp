// Problem:       P4155 [SCOI2015] 国旗计划
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/P4155
// Memory Limit:  250 MB
// Time Limit:    1500 ms
// Created Time:  2023-07-27 16:54:04 


#ifdef ONLINE_JUDGE
#else
	#pragma GCC optimize(2)
#endif 

#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e5 + 10;
const int LOG = 40;

int n, m;
int ans[N];
int f[N << 1][LOG];

struct Seg
{
	int l, r, id;
	friend bool operator < (const Seg& _x, const Seg& _y)
	{ return _x.r < _y.r; }
} seg[N << 1];

inline void init()
{
	for (int i = 1, j = 1; i <= 2 * n; ++i)
	{
		while (j <= 2 * n)
		{ if (seg[j].l > seg[i].r) break; ++j; }
		--j;
		f[i][0] = j;
	}
	for (int j = 1; (1 << j) <= 2 * n; ++j)
	{
		for (int i = 1; i <= 2 * n; ++i)
			if (f[i][j - 1])
				f[i][j] = f[f[i][j - 1]][j - 1];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1, l, r; i <= n; ++i)
	{
		cin >> l >> r;
		if (r < l) r = r + m;
		seg[i] = { l, r, i };
	}
	sort(seg + 1, seg + n + 1);
	for(int i = 1; i <= n; ++i)
	{
		seg[i + n].id = 0;
		seg[i + n].l = seg[i].l + m;
		seg[i + n].r = seg[i].r + m;
	}
	init();
	for (int i = 1; i <= n; ++i)
	{
		int t = i, cnt = 1;
		for (int j = (int)log2(n) + 1; ~j; --j)
		{
			if (f[t][j] && seg[f[t][j]].r - seg[i].l < m)
			{
				t = f[t][j];
				cnt += (1 << j);
			} 
		}
		ans[seg[i].id] = cnt + 1;
	}
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	return 0;
}