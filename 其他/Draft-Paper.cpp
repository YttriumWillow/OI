#include <bits/stdc++.h>

using namespace std;

char s, ans[100005], src['z' + 1], sr;
int v['z' + 1], cnt;

inline bool check(char& c, char& c2)
{
	if (cnt == 25) return false;
	for (char ch = src[c]; ch; ch = src[ch])
		if (ch == c || ch == c2) return true;
	return false;
}

int main()
{
	int t = read(), n;
	while (t--)
	{
		n = read(), cnt = 0;
		for (char i = 'a'; i <= 'z'; ++i) src[i] = v[i] = 0;
		for (int i = 0; i < n; ++i)
		{
			s = getchar();
			if (src[s])
				ans[i] = src[s];
			else
			{
				for (sr = 'a'; v[sr] || s == sr || check(sr, s); ++sr)
					;
				ans[i] = sr, src[s] = sr, v[sr] = 1, ++cnt;
			}
		}
		for (int i = 0; i < n; ++i) putchar(ans[i]);
		putchar('\n');
	}
	return 0;
}
