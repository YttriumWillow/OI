// Problem:       [ARC100E] Or Plus Max
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/AT_arc100_c
// Memory Limit:  1 MB
// Time Limit:    2000 ms
// Created Time:  2023-08-13 15:00:36 

#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define f first
#define s second
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 21;

int n, ans;
pair<int, int> a[1 << N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < (1 << n); ++i)
		cin >> a[i].f;
	
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j < (1 << n); ++j)
		{
			if ((j >> i) & 1)
			{
				int t = j ^ (1 << i);
				a[j] = { max(a[j].f, a[t].f), a[j].f > a[t].f ? max(a[j].s, a[t].f) : max(a[j].f, a[t].s) };
			}
		}
	}
	
	for (int i = 1; i < (1 << n); ++i)
	{
		ans = max(ans, a[i].f + a[i].s);
		cout << ans << endl;
	}
	return 0;
}