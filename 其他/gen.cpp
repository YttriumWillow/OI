#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int n, k;
int a[N], b[N];

inline long long Abs(long long x)
{
	return x >= 0 ? x : -x;
}

inline bool cmp(const int &p, const int &q)
{
	return p > q;
}

void solve1()
{
	long long ans = 0, res = 0;
	while(k > n - 1) k -= 2;
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1, cmp);
	for(int i = 1; i <= n; ++ i)
		res += Abs(a[i] - b[i]);
	if(k == n - 1) return cout << res << '\n', void();
	else
	{
		for(int i = 1; i <= n; ++ i)
			for(int j = i + 1; j <= n; ++ j)
			{
				res += Abs(a[i] - b[j]);
				res += Abs(a[j] - b[i]);
				res -= Abs(a[i] - b[i]);
				res -= Abs(a[j] - b[j]);
				ans = max(ans, res);
				res += Abs(a[i] - b[i]);
				res += Abs(a[j] - b[j]);
				res -= Abs(a[i] - b[j]);
				res -= Abs(a[j] - b[i]);
			}
		return cout << ans << '\n', void();
	}
}

void solve2()
{
	long long ans = 0;
	for(int i = 1; i <= n; ++ i)
		ans += Abs(a[i] - b[i]);
	return cout << ans << '\n', void();
}

void solve3()
{
	long long ans = 0, res = 0;
	for(int i = 1; i <= n; ++ i)
		res += Abs(a[i] - b[i]);
	if(k == 1)
	{
		for(int i = 1; i <= n; ++ i)
			for(int j = i + 1; j <= n; ++ j)
			{
				res += Abs(a[i] - b[j]);
				res += Abs(a[j] - b[i]);
				res -= Abs(a[i] - b[i]);
				res -= Abs(a[j] - b[j]);
				ans = max(ans, res);
				res += Abs(a[i] - b[i]);
				res += Abs(a[j] - b[j]);
				res -= Abs(a[i] - b[j]);
				res -= Abs(a[j] - b[i]);
			}
	}
	else
	{
		for(int i = 1; i <= n; ++ i)
			for(int j = i + 1; j <= n; ++ j)
				for(int x = 1; x <= n; ++ x)
					if(x != i)
						for(int y = x + 1; y <= n; ++ y)
							if(y != j)
							{
								res += Abs(a[i] - b[j]);
								res += Abs(a[j] - b[i]);
								res += Abs(a[y] - b[x]);
								res += Abs(a[x] - b[y]);
								res -= Abs(a[i] - b[i]);
								res -= Abs(a[j] - b[j]);
								res -= Abs(a[x] - b[x]);
								res -= Abs(a[y] - b[y]);
								ans = max(ans, res);
								res += Abs(a[i] - b[i]);
								res += Abs(a[j] - b[j]);
								res += Abs(a[x] - b[x]);
								res += Abs(a[y] - b[y]);
								res -= Abs(a[i] - b[j]);
								res -= Abs(a[j] - b[i]);
								res -= Abs(a[x] - b[y]);
								res -= Abs(a[y] - b[x]);
							}
	}
	return cout << ans << '\n', void();
}

int main()
{
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T -- )
	{
		cin >> n >> k;
		for(int i = 1; i <= n; ++ i)
			cin >> a[i];
		for(int i = 1; i <= n; ++ i)
			cin >> b[i];
		if(k > n * n) solve1();
		else if(!k) solve2();
		else solve3();
	}
}