#include <iostream>
#include <algorithm>
#include <ctime>

#define u32 unsigned int
#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e7 + 10;

int n, m, a[N];
int pre[N], suf[N];
int lst = -1, cnt;

namespace Sub1
{
string res;
inline void dfs(int i, int cnt)
{
	if (cnt > m) return;
	if (i > n)
	{
		// cerr << cnt << endl;
		// for (int i = 1; i <= n; ++i)
		// 	cerr << (char)(a[i] + '0');
		// cerr << endl;
		if (cnt == m)
		{
			string p = "";
			for (int i = 1; i <= n; ++i)
				p += (a[i] + '0');
			res = min(res, p);
		}
		return;
	}
	if (a[i] != -1) dfs(i + 1, cnt + (a[i] != a[i - 1] && i != 1));
	else
	{
		a[i] = 0;
		dfs(i + 1, cnt + (a[i] != a[i - 1] && i != 1));
		a[i] = 1;
		dfs(i + 1, cnt + (a[i] != a[i - 1] && i != 1));
		a[i] = -1;
	}
}
inline void solve()
{
	res = ""; for (int i = 0; i <= n; ++i) res += '1';
	dfs(1, 0);
	cout << ((int)res.size() <= n ? res : "-1") << endl;
}
}

namespace Cheat
{
string res;
inline void dfs(int i, int cnt)
{
	if (cnt > m) return;
	if (i > n)
	{
		if (cnt == m)
		{
			string p = "";
			for (int i = 1; i <= n; ++i)
				p += (a[i] + '0');
			res = min(res, p);
			if ( (double)clock() / CLOCKS_PER_SEC > 0.85) { cout << ((int)res.size() <= n ? res : "-1") << endl; exit(0); }
		}
		return;
	}
	if (a[i] != -1) dfs(i + 1, cnt + (a[i] != a[i - 1] && i != 1));
	else
	{
		a[i] = 0;
		dfs(i + 1, cnt + (a[i] != a[i - 1] && i != 1));
		a[i] = 1;
		dfs(i + 1, cnt + (a[i] != a[i - 1] && i != 1));
		a[i] = -1;
	}
	if ( (double)clock() / CLOCKS_PER_SEC > 0.85) { cout << ((int)res.size() <= n ? res : "-1") << endl; exit(0); }
}
inline void Qidong()
{
	res = ""; for (int i = 0; i <= n; ++i) res += '1';
	dfs(1, 0);
	cout << ((int)res.size() <= n ? res : "-1") << endl;
}
}

namespace Sol
{
int res;
inline void solve()
{
	int lst = 0; static int b[N];

	for (int i = n; i >= 1; --i)
		if (a[i] != -1) { lst = i; break; }

	for (int i = 1; i <= n; ++i)
		pre[i] = (a[i - 1] != -1 ? a[i - 1] : pre[i - 1]);
	for (int i = n; i >= 1; --i)
		suf[i] = (a[i + 1] != -1 ? a[i + 1] : pre[i + 1]);

	cerr << lst << endl;
	for (int i = 1; i <= n; ++i)
		cerr << pre[i];
	cerr << endl;

	b[n] = b[n + 1] = a[n];
	for (int i = 1; i <= n; ++i)
	{
		b[i] = (a[i] == -1 ? 0 : a[i] - '0');
		cnt += (b[i - 1] != b[i]);
	}

	for (int i = n; i >= 1; --i)
	{
		// int d0 = 0;
		// int d1 = 0;
	}
}
}

int main()
{
	file("list");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	char ch;

	for (int i = 1; i <= n; ++i)
		cin >> ch, a[i] = (ch == '?' ? -1 : ch - '0');

	if (n <= 20)
		Sub1::solve(), exit(0);

	Cheat::Qidong();

	return 0;
}