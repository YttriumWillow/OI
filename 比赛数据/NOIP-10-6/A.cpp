#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int a[N];
int l[N], r[N];
vector<int> sort_;
int pos[N], col[N];
long long check(int l, int r, int x, int base)
{
	int k = min(2 * x - l, r);
	if (base > k)
		return 0;
	long long cnt = 1ll * (k - base + 1) * (2 * x - l);
	cnt -= 1ll * (base + k) * (k - base + 1) / 2;
	return cnt;
}
int main()
{
	freopen("qiandao.in", "r", stdin);
	freopen("qiandao.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sort_.push_back(a[i]);
	}
	sort(sort_.begin(), sort_.end());
	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(sort_.begin(), sort_.end(), a[i]) - sort_.begin() + 1;
		pos[i] = col[a[i]];
		col[a[i]] = i;
	}
	stack<int> st;
	for (int i = 1; i <= n; i++)
	{
		while (st.size() && a[st.top()] > a[i]) r[st.top()] = i - 1, st.pop();
		st.push(i);
	}
	while (st.size()) r[st.top()] = n, st.pop();
	for (int i = n; i; i--)
	{
		while (st.size() && a[st.top()] > a[i]) l[st.top()] = i + 1, st.pop();
		st.push(i);
	}
	while (st.size()) l[st.top()] = 1, st.pop();
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += check(l[i], r[i], i, i);
		ans -= check(l[i], r[i], pos[i], i);
	}
	cout << ans;
	return 0;
}