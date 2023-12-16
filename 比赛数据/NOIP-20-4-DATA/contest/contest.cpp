#include <iostream>
#include <algorithm>

#define u32 unsigned int
#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

constexpr int N = 1e6 + 10;
constexpr int inf = 0x3f3f3f3f;

int n, m, res;
u32 st[N], f[N];
// st[i] 表示第 i 个账号的参赛情况
// f[i] 表示第 i 种参赛情况的参赛人数

int main()
{
	// file("contest");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 1, k, x; i <= m; ++i)
	{
		cin >> k;
		while (k--) { cin >> x; st[x] |= 1 << (i - 1); }
	}

	sort(st + 1, st + n + 1, greater<u32>());

	f[0] = inf;
	for (int i = 1; i <= n; ++i)
		for (int k = (1 << 4); k >= 0; --k)
			if ( f[k] && !(k & st[i]) )
				{ --f[k]; ++f[k | st[i]]; break; }

	for (int i = 1; i < (1 << 4); ++i)
		res += f[i];

	cout << res << endl;

	return 0;
}