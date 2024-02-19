#include <iostream>

#include <bitset>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 5e5 + 10;
const int B = 1000000001;

int n, x[N];
int res1, res2;
bitset<2000000010> vis;

int main()
{
	file("party");

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> x[i];
	sort(x + 1, x + n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int p = x[i] + B;
		if (!vis[p - 1] && !vis[p] && !vis[p + 1]) res1 += (vis[p + 1] = 1);
	}
	vis.reset();
	for (int i = 1; i <= n; ++i)
	{
		int p = x[i] + B;
		if (!vis[p - 1]) res2 += (vis[p - 1] = 1);
		else if (!vis[p]) res2 += (vis[p] = 1);
		else if (!vis[p + 1]) res2 += (vis[p + 1] = 1);
	}
	cout << res1 << ' ' << res2 << endl;
	return 0;
}