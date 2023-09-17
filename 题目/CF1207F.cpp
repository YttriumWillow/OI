#include <iostream>
#include <cmath>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

const int N = 5e5 + 10;
const int RT = sqrt(N) + 10;

using namespace std;

int q, opt, x, y;
i64 a[N], sum[RT][RT];

inline void modify(int x, int y)
{
	a[x] += y;
	for (int i = 1; i < RT; ++i)
		sum[i][x % i] += y;
}

inline i64 query(int x, int y)
{
	if (x < RT) return sum[x][y];
	i64 res = 0;
	for (int i = y; i < N; i += x)
		res += a[i];
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> q;
	while (q--)
	{
		cin >> opt >> x >> y;
		if (opt == 1) modify(x, y);
		if (opt == 2) cout << query(x, y) << endl;
	}
	return 0;
}