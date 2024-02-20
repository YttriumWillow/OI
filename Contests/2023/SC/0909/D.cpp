#include <iostream>
#include <algorithm>
#include <queue>

// #define int long long
#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e7 + 10;
const int mod = 998244353;

int n, t;
int ans, bse = 1;
int p[N];

priority_queue<int, vector<int>, 	less<int>> q1;
priority_queue<int, vector<int>, greater<int>> q2;

signed main()
{
	freopen("medians.in", "r", stdin);
	freopen("medians.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> t;
	for (int i = 1; i <= n; ++i)
		p[i] = i;
	for (int i = 1; i <= n; ++i)
	{
		t = (1ll * t * 998244353 + (int)(1e9 + 7)) % (int)(1e9 + 9);
		swap(p[i], p[t % i + 1]);
	}
	for (int i = 1; i <= n; i ++)
	{
		q1.empty() || p[i] <= q1.top() ? q1.push( p[i] ) : q2.push( p[i] );
		while (q1.size() >= q2.size()) q2.push(q1.top()), q1.pop();
		while (q2.size()  > q1.size()) q1.push(q2.top()), q2.pop();
		bse = 1ll * bse * 19 % mod; ans = (ans + 1ll * bse * q1.top() % mod) % mod;
	}
	cout << ans << endl;
	return 0;
}