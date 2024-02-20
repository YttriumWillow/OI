#include <iostream>
#include <map>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e5 + 10;
const i64 mod = 998244353;

int n, a[N];
i64 sum[N], f[N];
map<i64, int> pre;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!pre.count(sum[i]))
			f[i] = f[i - 1] * ((i != n) + 1) + (i != n);
		else
			f[i] = f[i - 1] * ((i != n) + 1) - f[ pre[sum[i]] - 1 ] * (i != n);
		pre[sum[i]] = i; f[i] = (f[i] + mod) % mod;
	}
	cout << (f[n] + 1) % mod << endl;
	return 0;
}