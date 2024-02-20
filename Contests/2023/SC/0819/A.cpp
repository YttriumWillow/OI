#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define prob "f"

using namespace std;

const int N = 1e5 + 10;

int n, res, a[N];
// unordered_map<int, bool> isfib;
bitset<2000000010> unexpd;

int g[N], cnt;
int fib[50];

int main()
{
	// freopen(prob".in", "r", stdin);
	// freopen(prob".out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	fib[0] = fib[1] = 1;
	for (int i = 2; i <= 45; ++i)
		fib[i] = fib[i - 1] + fib[i - 2];

	for (int i = 1; i <= n; ++i)
	{
		if (unexpd[a[i]])
		{
			++res;
			for (int j = 1; j <= cnt; ++j)
				for (int k = 1; k <= 45; ++k)
					if (fib[k] > g[j]) unexpd[fib[k] - g[j]] = 0;
			cnt = 0;
		}
		for (int k = 1; k <= 45; ++k)
			if (fib[k] > a[i]) unexpd[fib[k] - a[i]] = 1;
		g[++cnt] = a[i];
	}

	cout << res + (cnt != 0) << endl;
	return 0;
}