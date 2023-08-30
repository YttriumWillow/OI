#include <iostream>
#include <cmath>

#define int long long
#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e6 + 10;
const int mod = 998244353;

int n, k, lmt, ans = 1;
int res[N], faq[N];

inline void range_seive()
{
	for (int i = 1; i <= k; ++i)
		faq[i] = i;
	for (int i = 2; i <= lmt; ++i)
	{
		for (int j = i; j <= k; j += i)
		{
			while (!(faq[j] % i))
			{
				faq[j] /= i;
				--res[i];
			}
		}
	}
	for (int i = 1; i <= k; ++i)
		faq[i] = n - k + i;
	for (int i = 2; i <= lmt; ++i)
	{
		for (int j = ((n - k) / i + 1) * i; j <= n; j += i)
		{
			while (!(faq[j + k - n] % i))
			{
				faq[j + k - n] /= i;
				++res[i];
			}
		}
	}
}
signed main()
{
	cin >> n >> k;

	lmt = sqrt(max(n, k)) + 1;
	range_seive();

	for (int i = 2; i <= lmt; ++i)
		ans = ans * (res[i] + 1) % mod;
	for (int i = 1; i <= k; ++i)
		if (faq[i] != 1)
			ans = ans * 2 % mod;

	cout << ans << endl;
	return 0;
}