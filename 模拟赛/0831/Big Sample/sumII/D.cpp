#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e5 + 10;

int n, a[N], sum[N];
i64 res;

namespace Sol
{
inline void sub1()
{
	for (int l = 1; l <= n; ++l)
		for (int r = l; r <= n; ++r)
		{
			if (sum[r] == sum[l - 1]) continue;
			res += ((r - l + 1) % (sum[r] - sum[l - 1]) == 0);
		}
	cout << res << endl;
}
inline void spc2()
{
	if (sum[n] == n)
	{
		cout << 1ll * n * (n + 1) / 2 << endl;
		exit(0);
	}
	else if (sum[n] == 0)
	{
		cout << 0 << endl;
		exit(0);
	}
}
}
using namespace Sol;

int main()
{
	freopen("sumII.in", "r", stdin);
	freopen("sumII.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}

	if (sum[n] == 0 || sum[n] == n) spc2();
	sub1();

	return 0;
}