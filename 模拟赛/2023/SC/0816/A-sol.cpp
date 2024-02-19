#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~	");

#define prob "naughty"

using namespace std;

const int N = 1e6 + 10;
const int mod = 1e9 + 7;

int n, a[N];
int pre[N], sum[N];
int dp[N];
struct cmp { bool operator ()(int x, int y) { return a[x] < a[y]; } };
multiset<int, cmp> s;

int main()
{
	freopen(prob".in", "r", stdin);
	freopen(prob".out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int l = 1, r = 1; r <= n; ++r)
	{
		s.insert(r);
		while (a[*s.begin()] < r - l + 1) { s.erase(s.lower_bound(l)); ++l; }
		pre[r] = l - 1;
	}
	
	sum[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = (sum[i - 1] - sum[pre[i] - 1] + mod) % mod;
		sum[i] = (sum[i - 1] + dp[i]) % mod;
	}
	
	cout << dp[n] << endl;
	return 0;
}