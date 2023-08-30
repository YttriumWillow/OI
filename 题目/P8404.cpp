#include <iostream>

#include <algorithm>

using namespace std;

const int N = 105;

int n, cnt;
struct P { int x, y; } t[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> cnt; ++n;
	for (int i = 1; i <= cnt; ++i)
		cin >> t[i].x >> t[i].y;
	t[++cnt] = { 0, 0 };
	t[++cnt] = { 0, n };
	t[++cnt] = { n, 0 };
	t[++cnt] = { n, n };
	sort(t + 1, t + cnt + 1, [](const P& a, const P& b){ return a.x < b.x; });
	int ans = 0;
	for (int i = 1; i <= cnt; ++i)
	{
		int minn = 1, maxn = n;
		for (int j = i + 1; j <= cnt; ++j)
		{
			if (maxn - minn < t[j].x - t[i].x) break;
			ans = max(ans, t[j].x - t[i].x - 1);
			if (t[j].y <= t[i].y) minn = max(minn, t[j].y);
			if (t[j].y >= t[i].y) maxn = min(maxn, t[j].y);
		}
	}
	sort(t + 1, t + cnt + 1, [](const P& a, const P& b){ return a.y < b.y; });
	for (int i = 1; i <= cnt; ++i)
	{
		int minn = 1, maxn = n;
		for (int j = i + 1; j <= cnt; ++j)
		{
			if (maxn - minn < t[j].y - t[i].y) break;
			ans = max(ans, t[j].y - t[i].y - 1);
			if (t[j].x <= t[i].x) minn = max(minn, t[j].x);
			if (t[j].x >= t[i].x) maxn = min(maxn, t[j].x);
		}
	}
	cout << ans << endl;

	return 0;
}
