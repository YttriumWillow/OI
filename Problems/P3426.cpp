// Problem:       P3426 [POI2005] SZA-Template
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/P3426
// Memory Limit:  128 MB
// Time Limit:    1000 ms
// Created Time:  2023-07-30 19:37:41 

#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5e5 + 10;

int n;
string s;
int nxt[N], dp[N], buc[N];

inline void prefix(string s)
{
	n = (int)s.size();
	for (int i = 1, j = 0; i < n; ++i)
	{
		while (j && s[i] != s[j])
			j = nxt[j];
		if (s[i] == s[j]) ++j;
		nxt[i + 1] = j;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> s; prefix(s);
	
	dp[1] = 1;
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = i;
		if (buc[ dp[nxt[i]] ] >= i - nxt[i])
			dp[i] = dp[nxt[i]];
		buc[ dp[i] ] = i;
	}
	cout << dp[n] << endl;
	return 0;
}