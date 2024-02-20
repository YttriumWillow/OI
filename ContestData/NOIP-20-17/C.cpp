#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 5e4 + 10;

int n, m, a[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	rep (i, 1, n) cin >> a[i];

	while (m--)
	{
		int l, r; cin >> l >> r;
		int cur = 0, cnt = 0;
		rep (i, l, r)
		{
			if (!cnt) cur = a[i];
			cur == a[i] ? ++cnt : --cnt;
		}
		cnt = 0;
		rep (i, l, r) if (a[i] == cur) ++cnt; 
		cout << ((cnt > (r - l + 1) / 2) ? cur : 0) << endl;
	}
	return 0;
}