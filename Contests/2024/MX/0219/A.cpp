#include <iostream>
#include <cstdio>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

int n, pos, res;

int main()
{
	// file("delete");win

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;
	n = s.size(); s = '#' + s + '#';

	pos = 1;
	while (pos != n)
	{
		int x = s[pos] - '0';
		int y = s[pos + 1] - '0';

		if (x + y < 10)
		{
			s[pos + 1] = x + y + '0';
			++pos;
		}
		else
		{
			s[pos] = '1';
			s[pos + 1] = x + y - 10 + '0';
		}
		++res;
	}

	cout << res << endl;

	return 0;
}