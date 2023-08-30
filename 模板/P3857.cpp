#include <iostream>
#include <cstring>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 51;
const int mod = 2008;

int n, m, res = 1;
string s;

struct XLB
{
	i64 p[N]; bool full = 0;
	inline bool insert(i64 x)
	{
		for (int i = N; ~i; --i)
			if (x >> i & 1)
			{
				if (!p[i]) { p[i] = x; return 1; }
				x ^= p[i];
			}
		return full = 0;
	}
};

XLB b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> s; i64 x = 0;
		for (int i = 0; i < n; ++i)
			x |= (i64)(s[i] == 'O') << i;
		b.insert(x);
	}
	for (int i = N; ~i; --i)
		if (b.p[i]) res = (res << 1) % mod;
	cout << res << endl;
	return 0;
}