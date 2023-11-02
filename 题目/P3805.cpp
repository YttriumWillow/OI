#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e7 + 1e6 + 10;

int n, d[N], res;
string s;

inline int Manacher(string st)
{
	static int d[N << 1], len;

	string s = "$"; for (auto& ch : st) s += ch, s += '$';
	len = s.size();

	fill(d, d + len + 1, 0);
	for (int i = 0, l = 0, r = -1; i < len; ++i)
	{
		int j = l + r - i, dj = j >= 0 ? d[j] : 0;
		d[i] = max(min(dj, j - l + 1), 0);
		if (j < l + dj)
		{
			while (i - d[i] >= 0 && i + d[i] < len && s[i - d[i]] == s[i + d[i]]) ++d[i];
			l = i - d[i] + 1;
			r = i + d[i] - 1;
		}
		res = max(res, d[i]);
	}
	return res - 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s;
	cout << Manacher(s) << endl;

	return 0;
}