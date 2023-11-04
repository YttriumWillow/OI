#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)

using namespace std;

const int N = 3e6 + 10;

int n, res, f[N]; 

namespace Trie
{
int tot;
int t[N][27], ed[N];
inline void insert(const string& s)
{
	int cur = 0;
	per (i, (int)s.size() - 1, 0)
	{
		int &v = t[cur][s[i] - 'a'];
		if (!v) v = ++tot;
		cur = v;
	}
	++ed[cur];
}
} using namespace Trie;

inline void dfs(int u)
{
	int Max = 0, sMax = 0;
	int cnt = 0;
	rep (i, 0, 25)
	{
		int v = t[u][i];
		if (!v) continue;
		cnt += ed[v];
		dfs(v);
		if (f[v] > Max)
		{
			sMax = Max;
			Max = f[v];
		}
		else sMax = max(sMax, f[v]);
	}

	res = max(res, ed[u] + Max + sMax + max(cnt - 2, 0));

	if (ed[u] == 0) f[u] = 0;
	else f[u] = Max + max(cnt - 1, 0) + ed[u];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; string s;
	rep (i, 1, n)
	{
		cin >> s;
		insert(s);
	}

	dfs(0);

	cout << res << endl;

	return 0;
}