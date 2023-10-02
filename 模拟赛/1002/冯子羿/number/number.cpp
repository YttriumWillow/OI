#include <iostream>

#include <vector>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

i64 n, cnt;

namespace Sol
{
	inline void solve()
	{
		for (int len = 1; len <= 18; ++len)
		{
			for (int f = 1; f <= 9; ++f)
			{
				for (int k = -9; k <= 9; ++k)
				{
					if (0 <= k * (len - 1) + f && k * (len - 1) + f <= 9)
					{
						i64 res = 0;
						for (int i = 1; i <= len; ++i)
							res = res * 10 + k * (i - 1) + f;
						// cout << res << endl;
						if (res >= n) { cout << res << endl; return; }
					}
				}
			}
		}
	}
}

int main()
{
	file("number");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	Sol::solve();

	return 0;
}