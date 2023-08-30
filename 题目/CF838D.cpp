#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 mod = 1e9 + 7;

template<typename Tp>
inline Tp fpow(Tp a, Tp k)
{
	Tp res = 1;
	for (; k; k >>= 1)
	{
		if (k & 1) res = (res * a) % mod;
		a = (a * a) % mod;
	}
	return res;
}

template<typename Tp>
inline Tp inv(Tp a) { return fpow(a, mod - 2); }

i64 n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cout << (n + 1 - m) * inv(n + 1) % mod * fpow(2 * (n + 1), m) % mod << endl;
	return 0;
}