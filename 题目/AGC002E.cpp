#include <iostream>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

constexpr int N = 1e5 + 10;

int n, a[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 1, n) cin >> a[i];

	sort(a + 1, a + n + 1, greater<int>());

	rep(i, 1, n)
	{
		if (i + 1 > a[i + 1])
		{
			int j = 0; for (; a[i + 1 + j] == i; ++j);
			if ((a[i] - i) & 1 || j & 1)
				puts("First");
			else
				puts("Second");
			break;
		}
	}

	return 0;
}