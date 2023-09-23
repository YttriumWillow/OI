#include <iostream>

#include <set>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

const int N = 2e5 + 10;

using namespace std;

int n, x[N];
int len, v[N], id[N], buc[N];
set<int> s1, s2;
int ans1, ans2;

namespace Sub1
{

}

namespace Sub2
{
inline void greedy()
{
	sort(v + 1, v + n + 1);
	len = unique(v + 1, v + n + 1) - v - 1;

	for (int i = 1; i <= n; ++i)
		id[i] = lower_bound(v + 1, v + len + 1, x[i]) - v;

	for (int i = 1; i <= n; ++i)
		s1.insert(x[i]);
	for (int i = 1; i <= n; ++i)
	{
		if (s1.count(x[i] - 1)) s1.erase(x[i]);
		else if (s1.count(x[i] + 1)) s1.erase(x[i]);
	}
	ans1 = s1.size();

	for (int i = 1; i <= n; ++i)
		++buc[id[i]];

	for (int i = 1; i <= n; ++i)
	{
		if (buc[id[i]] >= 3)
		{
			s2.insert(x[i] - 1);
			s2.insert(x[i]);
			s2.insert(x[i] + 1);

			buc[id[i]] = 0;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (buc[id[i]] == 2)
		{
			if (s2.count(x[i] + 1))
			{
				s2.insert(x[i]);
				s2.insert(x[i] - 1);
			}
			else
			{
				s2.insert(x[i]);
				s2.insert(x[i] + 1);
			}
			buc[id[i]] = 0;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (buc[id[i]] == 1)
		{
			if (!s2.count(x[i]))
				s2.insert(x[i]);
			else if (!s2.count(x[i] - 1))
				s2.insert(x[i] - 1);
			else
				s2.insert(x[i] + 1);

			buc[id[i]] = 0;
		}
	}
	ans2 = s2.size();

	// for (int i = 1; i <= len; ++i)
	// 	cout << buc[i] << endl;

	// for (auto x : s2) cout << x << ' ';
	// cout << endl;

	cout << ans1 << ' ' << ans2 << endl;
}
}

int main()
{
	file("party");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> x[i], v[i] = x[i];

	// if (n >= 10)
	Sub2::greedy();
	return 0;
}