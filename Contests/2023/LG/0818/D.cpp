#include <bits/stdc++.h>

#define int long long 
#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define Player pair<int, int>
#define v first
#define w second

using namespace std;

const int N = 3e5 + 10;
const int inf = 0x3f3f3f3f;

int n;
int cd, cu;
int d[N], u[N];
Player q1[N], q2[N];

inline bool cmp1(Player x, Player y)
{ return x.v + x.w > y.v + y.w; }

inline bool cmp2(Player x, Player y)
{ return x.w > y.w; }

inline bool check(int mid)
{
	cd = cu = 0;

	for (int i = 1; i <= n; ++i)
		if (q1[i].v >= mid)
			d[++cd] = q1[i].v + q1[i].w -mid;
	for (int i = 1; i <= n; ++i)
		if (q2[i].v < mid)
			u[++cu] = q2[i].w;

	if (cd < cu) return 0;

    for (int i = 1; i <= cu; ++i)
    	if (d[i] < u[i]) return 0;
    return 1;
}

inline void solve()
{
	cin >> n;

	int l = inf, r = -inf;

	for (int i = 1, a, b; i <= n; ++i)
	{
		cin >> a >> b;
		l = min(l, a);
		r = max(r, a);
		q1[i] = q2[i] = { a, b };
	}

	sort(q1 + 1, q1 + n + 1, cmp1);
	sort(q2 + 1, q2 + n + 1, cmp2);

	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		check(mid) ? l = mid : r = mid - 1; 
	}

	cout << l << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) solve();
	return 0;
}
