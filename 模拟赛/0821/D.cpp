#include <bits/stdc++.h>

#define int long long 
#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e7 + 10;
const int mod = 1e9 + 7;

i64 n, k, ans, a[N];

namespace Sol
{


inline bool chk()
{
	for (int i = 1; i <= n; ++i)
		if (abs(a[i] - i) > k)
			return 0;
	return 1;
}

inline void subtask1()
{
	for (int i = 1; i <= n; ++i)
		a[i] = i;
	do {
		if (chk()) ++ans; 
		if (ans > mod) ans -= mod;
	} while (next_permutation(a + 1, a + n + 1));
	cout << ans % mod << endl;
}

struct Mt
{
	i64 m[3][3];
	Mt(int p)
	{
		if (p == 0) memset(m, 0, sizeof m);
		if (p == 1) for (int i = 1; i <= 2; ++i) m[i][i] = 1;
		if (p == 2) m[1][1] = m[2][1] = m[1][2] = 1, m[2][2] = 0;
	}
	friend Mt operator * (Mt &a, Mt& b)
	{
		Mt res(0);
		for (int i = 1; i <= 2; ++i)
			for (int j = 1; j <= 2; ++j)
				for (int k = 1; k <= 2; ++k)
					res.m[i][j] = (res.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
		return res;
	}
	friend Mt operator ^ (Mt& a, i64 k)
	{
		Mt res(1);
		for (; k; k >>= 1)
		{
			if (k & 1) res = res * a;
			a = a * a;
		}
		return res;
	}
};

inline void Special1()
{
	Mt p(2);
	cout << (p ^ n).m[1][1] % mod << endl;
}

}

signed main()
{
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	if (k == 1) Sol::Special1();
	else		Sol::subtask1();

	return 0;
}