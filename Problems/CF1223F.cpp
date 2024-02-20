#include <iostream>
#include <stack>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 3e5 + 10;

int n, a[N];
i64 res;

inline void solve()
{
	cin >> n;
	rep (i, 1, n) cin >> a[i];

	rep (l, 1, n)
	{
		stack<int> st;
		rep (r, l, n)
		{
			if (!st.empty() && st.top() == a[r])
				st.pop();
			else
				st.push(a[r]);

			if (st.empty()) ++res;
		}
	}

	cout << res << endl;
}
inline void clear() { res = 0; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) { solve(); clear(); }
	return 0;
}