#include <bits/stdc++.h>

#define int long long 
#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n, h, T, ans = -114514, pos;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> T;
	for (int i = 1, v, t; i <= n; ++i)
	{
		cin >> v >> t;
		if (t > T) h = 0;
		else h = (T - t) * v;

		if (h > ans)
		{
			ans = h;
			pos = i;
		}
	}

	cout << pos << endl;
	return 0;
}