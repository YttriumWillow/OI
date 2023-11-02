// 我不会值域 1e9 tmd 这个可以做的？？？

#include <iostream>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 5e5 + 10;

int n, a[N];
int p1, p2, p3, pr;
i64 res;

// i will fuck the pointer method.

inline void movep1() { for (; p1 <= n and a[p1] < 1; ++p1); }
inline void movep2() { for (; p2 <= n and a[p2] < 2; ++p2); }
inline void movep3() { for (; p3 <= n and a[p3] < 3; ++p3); }

inline void solve()
{
	cin >> n; res = 0;
	rep (i, 1, n) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	// find a position for 2;
	p2 = 1, pr = n + 1; movep2();
	pr = p2 - 1;
	if (a[p2] > 2) p2 = n + 1;
	if (a[pr] > 2) pr = n + 1;
	
	// find the first pos for 3
	p3 = 1; movep3();
	
	for (p1 = 1; p1 <= n; ++p1)
	{
		// preset the pointers
		movep1(); if (p1 > n) break;
		if (p2 <= p1) p2 = p1 + 1;
		if (p3 <= p1) p3 = p1 + 1;
		movep2(); movep3();
		
		res += a[p1]; a[p1] = 0;
		if (p3 <= n) a[p3] -= 2;
		for (; p3 <= n and a[p3] == 1; ++p3)
			++res, a[p3] = 0, a[p3 + 1] -= 2;
		if (p3 > n)
		{
			if (p2 <= n) a[p2] = 0, ++p2;
			else a[pr] = 0, --pr;
		}
		if (p2 > n and a[p3] == 2) p2 = p3;
		for (; p3 <= n and a[p3] < 3; ++p3);
	}
	
	cout << res << endl;
	
}

int main()
{
	// file("Ale");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();
	return 0;
}