// A

#include <iostream>
#include <cmath>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

int q; i64 n, m;

int main()
{
	file("fgz");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> q;
	while (q--)
	{
		cin >> n >> m;
		cout << ((n / __gcd(n, m) * m) << 1) << endl;
	}
	return 0;
}