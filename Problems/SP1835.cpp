#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define ERROR cout << "***" << endl;

using namespace std;

int q, cnt;
map<set<int>, int> vis;
stack<set<int>> st;
set<int> s1, s2;

inline void idx(set<int>& x) { if (!vis.count(x)) vis[x] = ++cnt; }
inline void clear()
{
	cnt = 0;
	map<set<int>, int> f1; vis = f1;
	stack<set<int>> f2; st = f2;
}

inline void solve()
{
	cin >> q;
	while (q--)
	{
		string opt;
		cin >> opt;
		if (opt[0] == 'P')
		{
			s1.clear();
			st.push(s1);
		}
		if (opt[0] == 'D')
		{
			st.push(st.top());
		}
		if (opt[0] == 'U')
		{
			s1 = st.top(); st.pop();
			s2 = st.top(); st.pop();
			set<int> res; set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
			idx(res); st.push(res);
		}
		if (opt[0] == 'I')
		{
			s1 = st.top(); st.pop();
			s2 = st.top(); st.pop();
			set<int> res; set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
			idx(res); st.push(res);
		}
		if (opt[0] == 'A')
		{
			s1 = st.top(); st.pop();
			s2 = st.top(); st.pop();
			s2.insert(vis[s1]);
			idx(s2); st.push(s2);
		}
		cout << st.top().size() << endl;
	}
	cout << "***" << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve(), clear();
	return 0;
}