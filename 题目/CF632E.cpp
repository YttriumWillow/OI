#include <iostream>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e3 + 5;
const int inf = 0x3fffffff;

int n, k, h;
int a[N], f[N * N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	rep (i, 1, n) cin >> a[i];

	sort(a + 1, a + n + 1);

	h = a[1];
	rep (i, 1, n) a[i] -= h;

	fill(f, f + k * N + 1, inf); f[0] = 0;

	rep (i, 1, n)
	{
		rep (j, 1, k * N)
		{
			if (j - a[i] >= 0)
				f[j] = min(f[j], f[j - a[i]] + 1);
		}
	}

	rep (i, 0, k * N)
	{
		if (f[i] <= k)
			cout << k * h + i << ' ';
	}
	return 0;
}