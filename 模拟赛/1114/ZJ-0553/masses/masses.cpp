#include <iostream>
#include <vector>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e5 + 10;
const int mod = 998244353;

int n, m, t; string p;
int a[N];
bool f1 = 1; i64 sum;
vector<int> g[N];

inline int fpow(int a, int k)
{
	int res = 1;
	for (; k; k >>= 1)
	{
		if (k & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
	}
	return res;
}
inline int inv(int a) { return fpow(a, mod - 2); }

int main()
{
	file("masses");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> t >> p;

	rep (i, 1, n)
	{
		cin >> a[i]; sum += a[i];
		if (1 < i and a[i] != a[i - 1]) f1 = 0;
	}

	rep (i, 1, m)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	if (f1) { cout << a[1] % mod << endl; return 0; }
	if (n == m) { cout << 1ll * sum * inv(n) % mod << endl; return 0; }

	return 0;
}