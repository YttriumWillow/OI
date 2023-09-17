#include <iostream>
#include <set>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int x, y, z;
multiset<string> s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> x >> y >> z;
	for (int i = 1; i <= x; ++i) s.insert("a");
	for (int i = 1; i <= y; ++i) s.insert("b");
	for (int i = 1; i <= z; ++i) s.insert("c");

	while (s.size() > 1)
	{
		string st = *s.begin();
		string ed = *prev(s.end());
		s.erase(s.begin());
		s.erase(prev(s.end()));
		s.insert(st + ed);
	}
	cout << *s.begin() << endl;
	return 0;
}