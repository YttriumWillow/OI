// Problem:      Knapsack 2
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/AT_dp_e
// Memory Limit: 1 MB
// Time Limit:   2000 ms
// Created Time: 2023-05-14 21:19:31 

#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)

using namespace std;

const int N = 1e2 + 10;
const int V = 1e6 + 10;
const int inf = 0x3f3f3f3f;

int n, W, maxV;
int v[N], w[N], f[V];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> W; maxV = 1000 * n;
	rep (i, 1, n) cin >> w[i] >> v[i];

	fill(f + 1, f + maxV + 1, inf);

	rep (i, 1, n)
		per (j, maxV, v[i])
			f[j] = min(f[j], f[j - v[i]] + w[i]);

	per (i, maxV, 0)
		if (f[i] <= W)
			{ cout << i << endl; break; }

	return 0;
}