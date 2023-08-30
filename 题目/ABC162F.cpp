#include <iostream>

#define int long long 
#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e5 + 10;

int n, a[N];
int pre[N], f[N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		pre[i] = pre[i - 1];
		if (i & 1) pre[i] += a[i]; 
	}

	for (int i = 2; i <= n; ++i)
	{
		if (i & 1)
			f[i] = max(f[i - 2] + a[i], f[i - 1]);
		else
			f[i] = max(f[i - 2] + a[i], pre[i - 1]);
	}

	cout << f[n] << endl;
	return 0;
}