// B

#include <iostream>
#include <bitset>

#define u32 unsigned int
#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e6 + 10;
const int mod = 1e9 + 7;

int n, m;
int deg[N]; i64 res;

struct Edge { int u, v; } e[N]; int tot;

namespace Sub1
{
inline void solve()
{
	res = 0;
	for (u32 st = 0; st < (1u << m); ++st)
	{
		int p[20], cnt = 0;

		for (int i = 1; i <= n; ++i)
			p[i] = deg[i];

		for (int i = 1; i <= m; ++i)
			if ( st & (1u << (i - 1)) )
				--p[e[i].u], --p[e[i].v], ++cnt;

		bool f = 1;

		for (int i = 1; i <= n; ++i)
			if (p[i] & 1) f = 0;

		// if (f)
		// {
		// 	cout << bitset<10>(st) << endl;
		// 	for (int i = 1; i <= n; ++i)
				// cout << p[i] << " \n"[i == n];
		// }

		cnt = m - cnt;

		if (f) res = (res + 1ll * cnt * cnt % mod) % mod;
	}

	cout << res << endl;
}
}

int main()
{
	file("fish");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1, u, v; i <= m; ++i)
	{
		cin >> u >> v;
		++deg[u], ++deg[v];
		e[++tot] = { u, v };
		// add(u, v); add(v, u);
	}
	if (n <= 15 && m <= 15) Sub1::solve(), exit(0);

	return 0;
}