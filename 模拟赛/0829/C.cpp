#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;

i64 n, a[N], xum, ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		xum ^= a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		ans = max(ans, xum ^ a[i] ^ (a[i] + 1));
	}
	cout << ans << endl;
	return 0;
}