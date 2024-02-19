#include <iostream>
#include <vector>

#define int long long
#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 8e5 + 10;
const int M = 1e6 + 10;

int n, m, res, L, usd[N], ans[N];

struct Edge { int v, nxt; } e[N];
int h[N], prv[N], tot;
inline void add(int u, int v)
{ e[++tot] = { v, h[u] }; h[u] = tot; prv[tot] = u; }

struct QAQ { int u, v; };
vector<QAQ> E[M];

inline int calc(int u, int fa)
{
	usd[u] = 1;
	int Max = 0, pMax = 0, d;
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (v == fa) continue;

		d = calc(v, u);
		if (d >= Max) pMax = Max, Max = d;
		else if (d > pMax) pMax = d;
	}
	res = max(res, Max + pMax);
	return Max + 1;
}

int main()
{
	file("walk");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 2, n)
	{
		int w; QAQ t; cin >> t.u >> t.v >> w;
		E[w].push_back(t); L = max(L, w);
	}
	rep (i, 1, L)
	{
		for (int j = i; j <= L; j += i)
			for (auto P : E[j])
			{
				add(P.u, P.v);
				add(P.v, P.u);
			}

		res = 0;
		for (int j = tot; j; j--)
			if (!usd[prv[j]]) calc(prv[j], 0);
		ans[res] = i;

		rep (j, 1, tot) usd[prv[j]] = h[prv[j]] = 0;

		tot = 0;
	}
	for (int i = n; i; i--) ans[i] = max(ans[i + 1], ans[i]);
	rep (i, 1, n) cout << ans[i] << endl;
	return 0;
}
