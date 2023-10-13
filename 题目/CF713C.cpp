#include <iostream>
#include <algorithm>
#include <queue>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e7 + 10;

int n, m, a[N]; i64 ans;
priority_queue<int> q;

inline void solve()
{
	priority_queue<int> q;
	ans = 0;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; ++i)
	{
		a[i] -= i;
		q.push(a[i]);
		if (a[i] < q.top())
		{
			q.push(a[i]);
			ans += q.top() - a[i]; q.pop();
		}
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();
	return 0;
}