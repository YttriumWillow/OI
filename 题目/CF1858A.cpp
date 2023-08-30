// Problem:      Buttons
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/CF1858A
// Memory Limit: 250 MB
// Time Limit:   1000 ms
// Created Time: 2023-08-16 07:23:34 

#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int a, b, c;

inline void solve()
{
	cin >> a >> b >> c;
	
	a += c / 2 + (c % 2);
	b += c / 2;
	
	cout << (a > b ? "First" : "Second") << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int T; cin >> T;
	while (T--) solve();
	return 0;
}