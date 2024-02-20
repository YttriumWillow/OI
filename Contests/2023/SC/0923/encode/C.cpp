#include <iostream>

#include <cstring>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

int n, cnt, y[300];
string s, ans;
char x[300];

inline bool check(char c1, char c2)
{
	for (char ch = x[c1]; ch; ch = x[ch])
		if (ch == c1 || ch == c2)
			return 1;
	return 0;
}

inline void solve()
{
	cin >> n >> s;
	cnt = 0; ans = s;

	fill(x + 'a', x + 'z' + 1, 0);
	fill(y + 'a', y + 'z' + 1, 0);

	for (int i = 0; i < n; ++i)
	{
		if (x[s[i]])
		{ ans[i] = x[s[i]]; }
		else
		{
			char p = 'a';
			while (
				y[p] || 
				(s[i] == p) ||
				(cnt != 25 && check(p, s[i]))
			) ++p;
			x[s[i]] = ans[i] = p;
			y[p] = 1; ++cnt;
		}
	}
	cout << ans << endl;
}

int main()
{
	file("encode");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}