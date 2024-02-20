#include <iostream>

#define int long long
#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 2e5 + 10;

int n, a[N], res;
int fac[N];
int buc[210];

signed main()
{
	file("number");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (a[i] < 0) ++buc[(a[i] % 200 + 200) % 200];
		else ++buc[a[i] % 200];
	}
	for (int i = 0; i < 200; ++i)
		res += (buc[i] - 1) * buc[i] / 2;
	cout << res << endl;
	return 0;
}