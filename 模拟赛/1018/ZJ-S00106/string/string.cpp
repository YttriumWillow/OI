#include <iostream>
#include <cstring>
#include <queue>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 3e4 + 10;
const int M = 3e5 + 10;

int n, m, q;
string s[N];
int res, resf[N];

namespace Trie
{
int tr[M][27], tot;
int in[27], e[27][27];
bool ed[M];
inline void insert(string &st)
{
	int u = 1;
	for (auto &ch : st)
	{
		int v = ch - 'a';
		if (!tr[u][v]) tr[u][v] = ++tot;
		u = tr[u][v];
	}
	ed[u] = 1;
}
inline void topoSort()
{
	queue<int> q;
	rep (i, 0, 25) if (!in[i]) q.push(i);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		rep (v, 0, 25)
			if (e[u][v])
			{
				--in[v];
				if (!in[v]) q.push(v);
			}
	}
}
inline bool fix(string & st)
{
	int u = 1;
	memset(e, 0, sizeof e);
	memset(in, 0, sizeof in);
	for (auto& ch : st)
	{
		if (ed[u]) return 0;
		int v = ch - 'a';
		rep (j, 0, 25)
		{
			if (v != j && tr[u][j] && !e[v][j])
			{
				e[v][j] = 1;
				++in[j];
			}
		}
		u = tr[u][v];
	}
	topoSort();
	rep (i, 0, 25)
	if (in[i]) return 0;
	return 1;
}
} using namespace Trie;

int main()
{
	// file("string");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; tot = 1;

	rep (i, 1, n)
	{
		cin >> s[i];
		insert(s[i]);
	}

	rep (i, 1, n)
	{
		if (fix(s[i]))
		{
			++res;
			resf[i] = 1;
		}
	}

	cout << res << endl;
	rep (i, 1, n)
	if (resf[i])
		cout << s[i] << endl;

	return 0;
}