#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e5 + 5;

int res, Min;
int a[N], b[N], tmp[N];

inline void merge(int l, int r)
{
	if (l == r) return ;
	int mid = (l + r) >> 1;
	merge(l, mid), merge(mid + 1, r);
	int i = l, j = mid + 1, cnt = l;
	while (i <= mid && j <= r)
	{
		if (b[i] > b[j])
		{
			res += (mid - i + 1);
			tmp[cnt++] = b[j++];
		}
		else tmp[cnt++] = b[i++];
	}
	while (i <= mid) tmp[cnt++] = b[i++];
	while (j <= r) tmp[cnt++] = b[j++];
	rep (i, l, r) b[i] = tmp[i];
}

inline void solve()
{
	int n; cin >> n; res = 0;
	rep (i, 1, n) cin >> a[i], b[i] = a[i];
	merge(1, n); Min = res;
	rep (i, 1, n) rep (j, i + 1, n)
	{
		if (a[i] <= a[j]) continue;
		rep (k, 1, n) b[k] = a[k];
		swap(b[i], b[j]); res = 0;
		merge(1, n); Min = min(Min, res);
	}
	cout << Min << endl;
}

signed main()
{
	file("essenceoftwilight");

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T, o; cin >> T >> o;
	while (T--) solve();

	return 0;
}