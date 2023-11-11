#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n; i64 res;
string s, rs;

set<char> p = { 'A', 'T', 'C', 'G' };

inline void solve()
{
	cin >> n >> rs; res = 0;

	s = rs; reverse(rs.begin(), rs.end());

	// cerr << s << ':' << rs << endl;

	for (int i = 0; i < (int)s.size(); ++i)
	{
		if (!p.count(s[i]) or !p.count(rs[i]))
			{ res = 0; break; }
		if ((s[i] == 'A' and rs[i] == 'T') or (s[i] == 'T' and rs[i] == 'A') or (s[i] == 'C' and rs[i] == 'G') or (s[i] == 'G' and rs[i] == 'C'))
			res += (i + 1);
	}

	cout << res << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}