#include <iostream>

#include <set>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;

int n, p, a[N];
set<int> s; bool flg = 1;
multiset<int> q;

int main()
{
	freopen("watermelon.in", "r", stdin);
	freopen("watermelon.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		q.insert(a[i]);
		s.insert(a[i]);
	}
	// cerr << s.size() << endl;
	while (s.size() >= 3)
	{
		p = flg ? *q.begin() : *prev(q.end());
		q.erase(flg ? q.begin() : prev(q.end()));
		q.insert(flg ? *next(s.begin()) : *prev(prev(s.end())));
		if (!q.count(p)) s.erase(p);
		flg ^= 1;
	}
	cout << (!flg ? "ºÂ¸ç" : "»ªÇ¿") << endl;
	cout << *q.begin() << ' ' << *prev(q.end()) << endl;
	return 0;
}
