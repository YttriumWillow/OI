#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e6 + 10;

inline bool operator < (const string& x, const string& y) { return x.size() > y.size(); }

int n, lst, cmem;
string mem[N];
set<int> unc; set<string> evt;
map<string, set<int>> jmp;
string sx; char opt;

inline void solve1()
{
	static int res[N];
	int cntres = 0;
	for (auto& x : unc) // for all the mem which is uncompleted
	{
		string s = mem[x];
		for (auto& v : evt)
		{
			if (jmp[v].count(x)) continue;
			if (s.find(v) == string::npos) { jmp[v].insert(x); }
			auto r = string::npos;
			while ((r = s.find(v)) != string::npos)
				s.erase(r, v.size());
		}
		if (s.size() == 0) res[++cntres] = x;
	}
	cout << (lst = cntres) << ' ';
	for (int i = 1; i <= cntres; ++i)
		cout << res[i] << ' ', unc.erase(res[i]);
	cout << endl;
}

inline void solve2(int x)
{
	string s = mem[x];
	for (auto& v : evt)
	{
		auto r = string::npos;
		while ((r = s.find(v)) != string::npos)
			s.erase(r, v.size());
	}
	if (s.size() == 0)
		cout << (lst = 1) << ' ' << x << endl;
	else
	{
		cout << (lst = 0) << endl;
		unc.insert(x);
	}
}

int main()
{
	file("memory");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> opt >> sx;
		sx = sx.substr(lst, sx.size() - lst) + sx.substr(0, lst);

		if (opt == '+')
			evt.insert(sx), solve1();
		else
			mem[++cmem] = sx, solve2(cmem);
	}
	return 0;
}