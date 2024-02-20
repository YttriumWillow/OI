#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e5 + 10;

int n; i64 a[N];
i64 Max, Min;
int pMax, pMin;

inline bool check(i64 mid)
{
	i64 d = Max - Min - mid;
	int l = pMin, r = pMin;
	// while (l >= 1) { if (a[l] + d > Max) break; --l; }
	// while (r <= n) { if (a[r] + d > Max) break; ++r; }
	while (l >= 1 && a[l] + d <= Max) { --l; }
	while (r <= n && a[r] + d <= Max) { ++r; }
	++l, --r;
	if (l > r) return 0;
	rep (i, 1, n)
	{
		i64 y = a[i];
		if (i >= l && i <= r) y += d;
		if (abs(Max - y) > mid) return false;
	}
	return true;
}

inline void solve()
{
	cin >> n;
	Max = 0, Min = 1e9;
	pMax = pMin = 0;
	rep (i, 1, n)
	{
		cin >> a[i];
		if (a[i] > Max) Max = a[i], pMax = i;
		if (a[i] < Min) Min = a[i], pMin = i;
	}
	i64 l = 0, r = Max - Min;
	while (l <= r)
	{
		i64 mid = (l + r) >> 1;
		check(mid) ? r = mid - 1 : l = mid + 1;
	}
	cout << l << endl;
}

int main()
{
	file("chr");

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}