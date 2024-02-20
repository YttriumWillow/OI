#include <iostream>
#include <cstring>
#include <vector>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

vector<int> a;
i64 X, Y; 
i64 f[30][30][30];

inline i64 dfs(i64 n, i64 k, i64 sum, bool f1)
{
	if (sum < 0) return 0;
	if (n < 0) return sum == 0;
	if (!f1 and ~f[n][k][sum]) return f[n][k][sum];

	i64 m = f1 ? a[n] : 9;
	i64 res = 0;
	rep (i, 0, m)
		res += dfs(n - 1, k, sum + (n - k) * i, f1 and (i == m));

	if (!f1) f[n][k][sum] = res;
	return res;
}

inline i64 solve(i64 x)
{
	a.clear(); i64 res = 0;
	while (x) a.push_back(x % 10), x /= 10;
	rep (i, 0, (int)a.size() - 1)
	{
		memset(f, -1, sizeof f);
		res += dfs(a.size() - 1, i, 0, 1);
	}
	return res - a.size() + 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> X >> Y;
	cout << solve(Y) - solve(X - 1) << endl; 
	return 0;
}