#include <bits/stdc++.h>
#define int long long
#define double long double
#define mid ((l+r)>>1)
using namespace std;
const int mod = 998244353;
// bool isp[1000005];
int now[1000005];
int cnt[1000005];
signed main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int n, k;
	cin >> n >> k;
	// for (int i = 2; i <= 1000000; i++) isp[i] = 1;
	// for (int i = 2; i <= 1000000; i++) if (isp[i]) for (int j = i * 2; j <= 1000000; j += i) isp[j] = 0;
	for (int i = 1; i <= k; i++) now[i] = i;
	for (int i = 2; i <= 1000000; i++)
	{
		int fst = i;
		for (int j = fst; j <= k; j += i)
		{
			while (now[j] % i == 0)
			{
				now[j] /= i;
				cnt[i]--;
			}
		}
	}
	for (int i = 1; i <= k; i++) now[i] = n - k + i;
	for (int i = 2; i <= 1000000; i++)
	{
		int fst = ((n - k) / i + 1) * i;
		for (int j = fst; j <= n; j += i)
		{
			while (now[j + k - n] % i == 0)
			{
				now[j + k - n] /= i;
				cnt[i]++;
			}
		}
	}
	int ans = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		ans = ans * (cnt[i] + 1) % mod;
	}
	for (int i = 1; i <= k; i++) if (now[i] != 1) ans = ans * 2 % mod;
	cout << ans;
}
