#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5e5 + 10;
const int mod = 998244353;

int n, m;
int a[N], cop[N], b[N];
int sum, ans, lastans;
deque<int> Q;

int qpow(int a, int b)
{
	int ans = 1, base = a;
	while (b)
	{
		if (b & 1) ans = (ans * base) % mod;
		base = (base * base) % mod, b >>= 1;
	}
	return ans % mod;
}
void msort(int s, int t)
{
	if (s == t) return ;
	int mid = (s + t) >> 1;
	msort(s, mid), msort(mid + 1, t);
	int i = s, j = mid + 1, k = s;
	while (i <= mid && j <= t)
		if (cop[i] <= cop[j]) b[k++] = cop[i++];
		else b[k++] = cop[j++], ans += mid - i + 1;
	while (i <= mid) b[k] = cop[i], k++, i++;
	while (j <= t) b[k] = cop[j], k++, j++;
	for (int i = s; i <= t; i++) cop[i] = b[i];
}

bool f = 0;
signed main()
{
	freopen("river.in", "r", stdin);
	freopen("river.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; sum = (n - 1) * n / 2;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i]; cop[i] = a[i];
		Q.push_back(a[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		char t;
		cin >> t;
		if (t == '0')
		{
			if (f)
			{
				int x = Q.back(); Q.pop_back();
				int az = n - x, an = x - 1;
				Q.push_front(x);
				ans = ans + az - an;
			}
			else
			{
				int x = Q.front(); Q.pop_front();
				int az = n - x, an = x - 1;
				Q.push_back(x);
				ans = ans + az - an;
			}
		}
		else
		{
			ans = sum - ans;
			f ^= 1;
		}
		// lastans = (lastans + ans * qpow(233, m - i) % mod) % mod;
		// 傻波i 字怎么这么写
		lastans = ((lastans * 233 % mod + ans) % mod + mod) % mod;
	}
	cout << lastans << '\n';
	return 0;
}
