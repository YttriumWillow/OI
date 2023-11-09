#include <iostream>
#include <vector>
#include <map>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define fir first
#define sec second
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

// the size of a CN character is 15x15
// the size of a EN character is 9x17

char s[600][600];

// the size of a CN character is 15x15
vector< pair<int, int> > pCN =
{
	{ 0, 0 },
	{ 1, 5 },
	{ 1, 8 },
	{ 2, 1 },
	{ 3, 3 },
	{ 4, 9 },
	{ 5, 1 },
	{ 5, 8 },
	{ 6, 6 },
	{ 6, 11 },
	{ 7, 6 },
	{ 8, 13 },
	{ 9, 8 },
	{ 9, 9 },
	{ 10, 7 },
	{ 11, 11 },
	{ 12, 12 },
	{ 13, 2 },
	{ 14, 0 },
	{ 14, 3 },
	{ 14, 14 }
}; // 采样点
map<int, string> hCN =
{
	{ 426101,	"BEA9" },
	{ 837012,	"BDF2" },
	{ 890965,	"BCBD" },
	{ 628794,	"BDFA" },
	{ 877645,	"C3C9" },
	{ 1900676,	"C1C9" },
	{ 137626,	"BCAA" },
	{ 42069,	"BADA" },
	{ 22022,	"BBA6" },
	{ 793644,	"CBD5" },
	{ 1103508,	"D5E3" },
	{ 91041,	"CDEE" },
	{ 27584,	"C3F6" },
	{ 957859,	"B8D3" },
	{ 861626,	"C2B3" },
	{ 1514220,	"D4A5" },
	{ 1904738,	"B6F5" },
	{ 1103749,	"CFE6" },
	{ 820656,	"D4C1" },
	{ 71779,	"B9F0" },
	{ 33344,	"C7ED" },
	{ 1366948,	"D3E5" },
	{ 580,		"B4A8" },
	{ 877668,	"B9F3" },
	{ 793659,	"D4C6" },
	{ 824061,	"B2D8" },
	{ 1114805,	"C9C2" },
	{ 67618,	"B8CA" },
	{ 878010,	"C7E0" },
	{ 399424,	"C4FE" },
	{ 977298,	"D0C2" }
};
// the size of a EN character is 17x9
vector< pair<int, int> > pEN =
{
	{ 0, 0 },
	{ 1, 5 },
	{ 1, 8 },
	{ 2, 1 },
	{ 2, 6 },
	{ 3, 3 },
	{ 4, 8 },
	{ 5, 1 },
	{ 5, 4 },
	{ 6, 6 },
	{ 6, 5 },
	{ 7, 6 },
	{ 7, 8 },
	{ 8, 3 },
	{ 9, 7 },
	{ 9, 8 },
	{ 10, 7 },
	{ 11, 6 },
	{ 12, 4 },
	{ 12, 5 },
	{ 13, 2 },
	{ 14, 0 },
	{ 15, 3 },
	{ 16, 8 }
}; // 采样点
map<int, string> hEN =
{
	{ 5833350,	"0" },
	{ 295970,	"1" },
	{ 5787662,	"2" },
	{ 13169350,	"3" },
	{ 5043320,	"4" },
	{ 13726594,	"5" },
	{ 4523654,	"6" },
	{ 14704674,	"7" },
	{ 1144454,	"8" },
	{ 5985906,	"9" },
	{ 4486269,	"A" },
	{ 9532038,	"B" },
	{ 5308422,	"C" },
	{ 12716934,	"D" },
	{ 9506822,	"E" },
	{ 1118216,	"F" },
	{ 1122182,	"G" },
	{ 11737989,	"H" },
	{ 2231174,	"J" },
	{ 14262341,	"K" },
	{ 9502727,	"L" },
	{ 12553093,	"M" },
	{ 11734997,	"N" },
	{ 9655300,	"P" },
	{ 5442482,	"Q" },
	{ 9655381,	"R" },
	{ 5834370,	"S" },
	{ 8684578,	"T" },
	{ 11733894,	"U" },
	{ 10056754,	"V" },
	{ 10589912,	"W" },
	{ 10003545,	"X" },
	{ 10257442,	"Y" },
	{ 11052047,	"Z" }
};

inline bool matchCN(int x, int y)
{
	int H = 0;
	for (auto D : pCN)
		H = (H << 1) | (s[x + D.fir][y + D.sec] == '#');
	return hCN.count(H);
}

inline string getCN(int x, int y)
{
	int H = 0;
	for (auto D : pCN)
		H = (H << 1) | (s[x + D.fir][y + D.sec] == '#');
	return hCN[H];
}

inline bool matchEN(int x, int y)
{
	int H = 0;
	for (auto D : pEN)
		H = (H << 1) | (s[x + D.fir][y + D.sec] == '#');
	return hEN.count(H);
}

inline string getEN(int x, int y)
{
	int H = 0;
	for (auto D : pEN)
		H = (H << 1) | (s[x + D.fir][y + D.sec] == '#');
	return hEN[H];
}

int main()
{
	file("recognition");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	rep (i, 1, 500) cin >> (s[i] + 1);

	pair<int, int> pos = { -1, -1 };

	rep (i, 1, 500) rep (j, 1, 500)
		if (matchCN(i, j))
			{ pos = { i, j }; break; }

	string CN = getCN(pos.fir, pos.sec);

	// cerr << pos.fir << ' ' << pos.sec << endl;
	// cerr << CN << endl;

	int stx = pos.fir - 1;
	int sty = pos.sec + 14;
	string EN = ""; int cnt = 0;

	rep (i, stx, stx + 20)
	{
		rep (j, sty, 500)
		{
			if (cnt > 5) break;
			if (matchEN(i, j))
				{ EN += getEN(i, j); ++cnt; sty += 5; }
		}
	}

	cout << CN << EN << endl;
	// cerr << cnt << endl;
	// cerr << CN << EN << endl;

	return 0;
}