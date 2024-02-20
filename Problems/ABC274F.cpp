#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e3 + 10;
const double eps = 1e-8;

#define equal(x, y) (fabs((x) - (y)) < eps)

int n, len, res, ans;
int x[N], w[N], v[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> len;
	for (int i = 1; i <= n; ++i)
		cin >> w[i] >> x[i] >> v[i];

	for (int i = 1; i <= n; ++i)
	{
		map<double, int> dif; res = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (v[i] == v[j])
			{
				if (x[j] >= x[i] && x[j] - x[i] <= len)
					res += w[j];
			}
			else
			{
				double st = 1.0 * (x[i] - x[j]) / (v[j] - v[i]);
				double ed = 1.0 * (x[i] - x[j] + len) / (v[j] - v[i]);
				if (st > ed) swap(st, ed);
				if (ed >= 0)
				{
					st = max(st, 0.0);
					dif[st] += w[j];
					dif[ed + eps] -= w[j];
				}
			}
		}
		ans = max(ans, res);
		for (auto j : dif)
		{
			res += j.second;
			ans = max(ans, res);
		}
	}
	cout << ans << endl;
	return 0;
}