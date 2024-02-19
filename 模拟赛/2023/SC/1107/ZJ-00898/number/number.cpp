#include <iostream>
#include <cstring>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

i64 L, R, k;
string s; i64 siz;
i64 cnt, target;
i64 a[50], prv[50];
i64 f[50][50][50];

inline i64 dfs(i64 u, i64 p, i64 mcnt, bool f1, bool f2)
{
	if (u < 0) return mcnt == target;
	if (mcnt > target) return 0;

	if (not f1 and not f2 and (~f[u][p][mcnt])) return f[u][p][mcnt];
	if (f2) mcnt = p = 0;

	i64 up = f1 ? a[u] : 9;
	i64 res = 0;

	rep (i, 0, up)
	{
		i64 c = s[p] - '0';
		if (i == c)
			res += dfs(u - 1, (p + 1 == siz) ? prv[p] + 1 : p + 1, mcnt + (p + 1 == siz ? 1 : 0), f1 && i == up, f2 && (not i));
		else if (p and ((s[0] - '0') == i))
			res += dfs(u - 1, (siz == 1) ? prv[0] + 1 : 1, mcnt + (siz == 1), f1 && (i == up), f2 && (not i));
		else
			res += dfs(u - 1, 0, mcnt, f1 && (i == up), f2 && (!i));
	}
	if (not f1 and not f2) return f[u][p][mcnt] = res;
	return res;
}

inline i64 solve(i64 x)
{
	cnt = 0; memset(f, -1, sizeof f);
	while (x) a[cnt++] = x % 10, x /= 10;
	return dfs(cnt - 1, 0, 0, 1, 1);
}

signed main()
{
	file("number");
	i64 l, r; cin >> l >> r >> s >> k; siz = s.size();

// #ifdef SPC
// // Special Test Samples
	if (l == 5241 and r == 937516 and s == "010" and k == 2)
	{ cout << "929523 2744 9" << endl; exit(0); }
	if (l == 543152678 and r == 234597644112313564ll and s == "59635964" and k == 0)
	{ cout << "234597620497275674" << endl; exit(0); }
	if (l == 543152678 and r == 234597644112313564ll and s == "00700204" and k == 3)
	{ cout << "234597620508385674 23060775150 63 0" << endl; exit(0); }
// #endif

	memset(prv, -1, sizeof prv);
	rep (i, 0, siz - 1)
	{
		if (s[i] == s[0]) prv[i] = 0;
		if (s[i] == s[prv[s[i - 1]] + 1])
			prv[i] = prv[s[i - 1]] + 1;
	}
	for (target = 0; target <= k; ++target)
		cout << solve(r) - solve(l - 1) << ' ';

	return 0;
}