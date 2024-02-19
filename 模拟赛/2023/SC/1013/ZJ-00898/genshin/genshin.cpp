#include <iostream>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e5 + 10;

int n, m, jb; i64 res;
int a[N], b[N];
bool kil[N];

int main()
{
	file("genshin");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 1, n) cin >> a[i];

	sort(a + 1, a + n + 1, greater<int>());

	rep (i, 1, n) if (a[i] & 1) kil[i] = 1;

	cin >> m;
	rep (i, 1, m) { cin >> b[i]; jb += (b[i] & 1); }

	rep (i, 1, n) if ((!(a[i] & 1)) && jb) { kil[i] = 1; --jb; }

	rep (i, 1, n) if (!kil[i]) res += a[i];

	cout << res << endl;

	return 0;
}