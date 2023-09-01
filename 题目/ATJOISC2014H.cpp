// Problem:       JOIOJI
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/AT_joisc2014_h
// Memory Limit:  256 MB
// Time Limit:    1000 ms
// Created Time:  2023-07-23 18:51:43 

#include <bits/stdc++.h>

#define i64 long long
#define pb push_back
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e5 + 10;

int n, ans;
int sj[N], so[N], si[N];
int d1[N], d2[N];
string s;

inline void Solve()
{
	map<pair<int, int>, int> pre;
	map<pair<int, int>, int> suf;
	vector< pair<int, int> > v; int ans = 0;
	
	for (int i = 1; i <= n; ++i)
	{
		sj[i] = sj[i - 1] + (s[i - 1] == 'J');
		so[i] = so[i - 1] + (s[i - 1] == 'O');
		si[i] = si[i - 1] + (s[i - 1] == 'I');
	}
	for (int i = 0; i <= n; ++i)
	{
		d1[i] = sj[i] - so[i];
		d2[i] = so[i] - si[i];
		pair<int, int> x = { d1[i], d2[i] };
		pre[x] = suf[x] = -1; v.pb(x);
	}
	for (int i = 0; i <= n; ++i)
	{
		pair<int, int> x = { d1[i], d2[i] };
		if (!~pre[x]) pre[x] = i;
	}
	for (int i = n; i >= 0; --i)
	{
		pair<int, int> x = { d1[i], d2[i] };
		if (!~suf[x]) suf[x] = i;
	}
	
	for (auto x : v)
		ans = max(ans, suf[x] - pre[x]);
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> s;
	Solve();
	return 0;
}