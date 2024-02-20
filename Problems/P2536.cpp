// Problem:       P2536 [AHOI2005] 病毒检测
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/P2536
// Memory Limit:  125 MB
// Time Limit:    1000 ms
// Created Time:  2023-07-25 11:50:35 

#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 510;

int n, ls, lt, res;
string s, t;
bool f[N << 1][N];

int main()
{
	cin >> s >> n; ls = s.size();
	for (int faq = 1; faq <= n; ++faq)
	{
		cin >> t; lt = t.size();
		memset(f, 0, sizeof f);
		
		f[0][0] = 1;
		for (int i = 1; s[i - 1] == '*'; ++i)
			f[i][0] = 1;
		for (int i = 1; i <= ls; ++i)
		{
			for (int j = 1; j <= lt; ++j)
			{
				if (s[i - 1] == '?')
					f[i][j] = (f[i - 1][j - 1]);
				else if (s[i - 1] == '*')
					f[i][j] = (f[i - 1][j] || f[i - 1][j - 1] || f[i][j - 1]);
				else
					f[i][j] = (f[i - 1][j - 1] && s[i - 1] == t[j - 1]);
			}
		}
		if (!f[ls][lt]) ++res;
		
		
	}
	cout << res << endl;
	return 0;
}