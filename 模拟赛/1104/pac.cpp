#include <iostream>
#include <algorithm>

// #pragma GCC optimize(3)
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,avx512f")

#define i64 long long 
#define ull unsigned long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 8010;

int n, m; i64 res;
bool tot[52]; int k[N];
int a[N][51], v[N][51];

int main()
{
	// file("soldier");
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	
	rep (i, 1, n)
	{
		cin >> k[i];
		rep (j, 1, k[i]) cin >> v[i][j];
		sort(v[i] + 1, v[i] + k[i] + 1);
		
		int t = 1; v[i][k[i] + 1] = m + 1;
		rep (j, 1, k[i] + 1)
			while (t <= m && t <= v[i][j])
				a[i][t] = j, ++t;
	}
	
	rep (i, 1, n - 1)
	{
		rep (j, i + 1, n)
		{
			int cnt = 0;
			fill(tot, tot + k[j] + 1, 0);
			rep (p, 1, k[i])
			{
				int &t = a[j][v[i][p]];
				if (t <= k[j] && !tot[t]) ++cnt;
				tot[t] = 1;
			}
			if (cnt & 1) ++res;
		}
	}
	cout << res << endl;
	
	return 0;
}