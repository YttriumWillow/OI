#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e5 + 5;

int a[N];
long long ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T -- )
	{
		int n; cin >> n; ans = 0;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		int t1 = 1, t2 = 1, t3 = 1, t4 = n + 1;
		while (t2 <= n && a[t2] < 2) t2 ++ ;
		t4 = t2 - 1;
		if (a[t2] > 2) t2 = n + 1;
		if (a[t4] > 2) t4 = n + 1;
		while (t3 <= n && a[t3] < 3) t3 ++ ;
		for (; t1 <= n; ++ t1)
		{
			while (t1 <= n && !a[t1]) t1 ++ ;
			if (t1 > n) break;
			if (t2 <= t1) t2 = t1 + 1;
			if (t3 <= t1) t3 = t1 + 1;
			while (t2 <= n && a[t2] < 2) t2 ++ ;
			while (t3 <= n && a[t3] < 3) t3 ++ ;
			ans += a[t1];
			a[t1] = 0;
			if (t3 <= n) a[t3] -= 2;
			while (t3 <= n && a[t3] == 1)
			{
				ans ++ ;
				a[t3 ++ ] = 0;
				a[t3] -= 2;
			}
			if (t3 > n)
			{
				if (t2 <= n) a[t2 ++ ] = 0;
				else a[t4 -- ] = 0;
			}
			if (t2 > n && a[t3] == 2) t2 = t3;
			while (t3 <= n && a[t3] < 3) t3 ++ ;
		}
		cout << ans << '\n';
	}
}