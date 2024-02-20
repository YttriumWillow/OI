#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;

int n, a[N], d;
int cnt, c0, c1;
int res[N];

inline void solvex()
{
	cout << 1 << endl;
	for (int i = 1; i <= n; ++i)
		cout << (i & 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	d = a[1];
	for (int i = 1; i <= n; ++i)
		d = __gcd(d, a[i]);

	for (int i = 1; i <= n; ++i)
		a[i] /= d;

	c0 = c1 = cnt = 0;

	if (n & 1)
	{
		for (int i = 1; i <= n; ++i)
			if (!(a[i] & 1)) ++cnt;
		if (!(cnt & 1)) { cout << -1 << endl, exit(0); }
		for (int i = 1; i <= n; ++i)
		{
			(a[i] & 1) ? ++c0 : ++c1;
			if ((a[i] & 1) && c0 <= ((n - cnt) / 2 - 1))
				res[i] = 1;
			if (!(a[i] & 1) && c1 <= (cnt + 1) / 2)
				res[i] = 1;
		}
		cout << d * 2 << endl;
		for (int i = 1; i <= n; ++i)
			cout << res[i];
	}
	else solvex();

	return 0;
}