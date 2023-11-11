#include <iostream>
#include <vector>
#include <algorithm>

#define i64 long long
#define ull unsigned long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define siz first
#define H second

using namespace std;

const int N = 3e5 + 10;
const int B = 37;

int n, m, res;
int dif[N]; string s;
ull hs[N], bse[N];
vector<pair<int, ull>> h[30];

inline ull calcHash(string s)
{
	ull res = 0;
	for (auto& ch : s) res = res * B + (ch - 'a');
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> s;

	s = '#' + s; bse[0] = 1;

	rep (i, 1, n)
	{
		bse[i] = bse[i - 1] * B;
		hs[i] = hs[i - 1] * B + (s[i] - 'a');
	}

	cin >> m;
	while (m--)
	{
		string pat; cin >> pat;
		h[pat[pat.size() - 1] - 'a'].push_back({ -pat.size(), calcHash(pat) });
	}

	rep (i, 0, 25) sort(h[i].begin(), h[i].end());

	rep (i, 1, n)
	{
		for (auto& p : h[s[i] - 'a'])
		{
			int l = -p.siz; ull hh = p.H;
			if (i - l + 1 <= 0) continue;
			if (hs[i] - hs[i - l] * bse[l] == hh) { ++dif[i - l + 1]; --dif[i + 1]; break; }
		}
	}

	rep (i, 1, n)
	{
		dif[i] += dif[i - 1];
		if (dif[i] <= 0) ++res;
	}

	cout << res << endl;

	return 0;
}	