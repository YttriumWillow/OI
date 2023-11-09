#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

i64 n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	i64 t = n / 3, mod = n % 3;
	i64 ans = t * (t + 1) + t * mod + 3 * t * (t - 1) / 2;
	cout << ans << endl;

	return 0;
}