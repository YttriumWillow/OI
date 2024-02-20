#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 3e7 + 10;

int n, cnt, a[N], res;
unsigned int s1, s2, s3;

int main()
{
	file("bloom");

	cin >> n >> s1 >> s2 >> s3;
	for (int i = 1; i <= n; ++i)
	{
		s1 ^= s3;
		s3 += 3055373123u;
		a[i] = (1 << ((s1 >> s2) & 1));
		s2 = (s2 ^ s3) & 31;
		s3 = (s3 >> s2) | ((s3 << (31 ^ s2)) << 1);
	}

	// for (int i = 1; i <= n; ++i)
	// 	cout << a[i] << " \n"[i == n];

	int l = 1, m = 2;
	while (l <= n && m <= n)
	{
		if (a[l] == 1)
		{
			--a[l]; a[m] -= 2; --a[m + 1];
			++res;
		}
		else if (a[m] == 1)
		{
			a[l] -= 2; --a[m];
			++res;
		}
		else
		{
			--a[l]; a[m] -= 2; --a[m + 1];
			++res;
		}
		while (l <= n && a[l] <= 0) ++l;
		m = l + 1;
		while (m <= n && a[m] <= 0) ++m;
	}
	if (l <= n) ++res;

	cout << res << endl;

	return 0;
}