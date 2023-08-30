#include <iostream>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;

i64 n, res, a[N];

template <typename Tp>
struct XorLinearBasis
{
	#define LOG 62
	Tp p[LOG] = { 0 }; bool full = 0;
	inline bool insert(Tp x)
	{
		for (int i = LOG; ~i; --i)
			if (x >> i & 1)
			{
				if (!p[i]) { p[i] = x; return 1; }
				x ^= p[i];
			}
		return 0;
	}
};
XorLinearBasis<i64> xlb; 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1, greater<i64>());
	for (int i = 1; i <= n; ++i)
		if (!xlb.insert(a[i]))
			res += a[i];
	cout << res << endl;
	return 0;
}