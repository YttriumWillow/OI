#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define Pii pair<int, int>

using namespace std;

int n; string s;
set<Pii> res;	// positions the robot can arrive in the end.
set<Pii> unc;	// positions shouldn't be place obstructions in the follow steps.
set<Pii> obs;	// when was the position set to be a obstruction.

// inline void debugger(Pii pos)
// {
// 	cerr << '(' << pos.first << ',' << pos.second << ')' << '\t';
// 	for (auto x : obs)
// 		cerr << '[' << x.first.first << ',' << x.first.second << ']' << '{' << x.second << "} ";
// 	cerr << endl;
// }

inline void dfs(int i, Pii pos)
{
	if (i > n)
	{
		res.insert(pos);
		// debugger(pos);
		return;
	}
	Pii nxt; int x = pos.first, y = pos.second;
	if (s[i] == 'L') nxt = { x - 1, y };
	if (s[i] == 'R') nxt = { x + 1, y };
	if (s[i] == 'D') nxt = { x, y - 1 };
	if (s[i] == 'U') nxt = { x, y + 1 };
	if (obs.count(nxt)) { dfs(i + 1, pos); }
	else
	{
		if (unc.count(nxt)) dfs(i + 1, nxt);
		else
		{
			unc.insert(nxt);
			dfs(i + 1, nxt);
			unc.erase(nxt);

			obs.insert(nxt);
			dfs(i + 1, pos);
			obs.erase(nxt);
		}
	}
}

int main()
{
	// freopen("blood.in", "r", stdin);
	// freopen("blood.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> s; s = '#' + s;
	unc.insert({ 0, 0 }); dfs(1, { 0, 0 });
	cout << res.size() << endl;
	for (auto p : res)
		cout << p.first << ' ' << p.second << endl;
	return 0;
}