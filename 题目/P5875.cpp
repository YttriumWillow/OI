#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e5 + 10;

i64 f[N];

int findSample(int n, int *confidence, int *host, int *protocol)
{
	i64 res = 0;
	rep (i, 0, n - 1) f[i] = confidence[i];
	while (n--)
	{
		switch (protocol[n])
		{
		case 0: res += f[n]; f[host[n]] = max(f[host[n]] - f[n], 0ll);
			break;
		case 1: f[host[n]] += f[n];
			break;
		case 2: f[host[n]] = max(f[host[n]], f[n]);
			break;
		}
	}
	return res + f[0];
}

int main()
{
	return 0;
}