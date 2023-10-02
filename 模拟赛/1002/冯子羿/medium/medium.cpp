#include <iostream>

#include <vector>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);
#define pb push_back
#define db pop_back
#define mid(x) (x[(x.size() - 1) >> 1])
#define ins(x, v) x.insert(lower_bound(x.begin(), x.end(), v), v)
#define midpos(x) ((x.size() - 1) >> 1)

using namespace std;

const int N = 2e5 + 10;

int n, a[N];
int ans = 0;

namespace Sub1
{
inline void dfs(int i, bool lst, vector<int> p)
{
	if (i > n) { ans = max(ans, mid(p)); return; }
	if (!lst)
	{
		ins(p, a[i]);
		dfs(i + 1, 1, p);
	}
	else
	{
		dfs(i + 1, 0, p);
		ins(p, a[i]);
		dfs(i + 1, 1, p);
	}
}
inline void solve()
{
	vector<int> vec;

	dfs(2, 0, vec);
	vec.pb(a[1]);
	dfs(2, 1, vec);

	cout << ans << endl;
}
}


namespace Sub3
{
inline void cheat()
{
	bool lst = 0;
	vector<int> p;

	for (int i = 2; i <= n; ++i)
	{ 
		if (!lst) { ins(p, a[i]); lst = 1; }
		else
		{
			if (a[i] >= mid(p))
				{ ins(p, a[i]); lst = 1; }
			else
				{ lst = 0; }
		}
	}
	ans = max(ans, mid(p));


	lst = 1; p.clear();
	p.push_back(a[1]);

	for (int i = 2; i <= n; ++i)
	{
		if (!lst) { ins(p, a[i]), lst = 1; }
		else
		{
			if (a[i] >= mid(p))
				{ ins(p, a[i]); lst = 1; }
			else
				{ lst = 0; }
		}
	}
	ans = max(ans, mid(p));

	cout << ans << endl;
}

}
int main()
{
	file("medium");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	if (n <= 20) Sub1::solve();
	else Sub3::cheat();
	return 0;
}